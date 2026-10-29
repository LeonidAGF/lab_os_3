#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define ll long long

typedef struct {
    int *a;
    ll n;
    int tnum, colthreads;
} sarg;

typedef struct {
    int *a, *buf;
    ll n, width;
    int tnum, colthreads;
} marg;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int done_count = 0;
ll block_size = 16;

void *sort_blocks(void *p) {

    sarg *s = p;
    
    ll blocks = (s->n + block_size - 1) / block_size;
    
    for (ll b = s->tnum; b < blocks; b += s->colthreads) {
        ll l = b * block_size, r = l + block_size;
        if (r > s->n)
            r = s->n;

        for (ll i = l + 1; i < r; i++) {
            int x = s->a[i];
            ll j = i - 1;
            while (j >= l && s->a[j] > x) {
                s->a[j + 1] = s->a[j];
                j--;
            }
            s->a[j + 1] = x;
        }
    }

    pthread_mutex_lock(&mutex);
    done_count++;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);

    return NULL;
}

void *Merge(void *p) {

    marg *m = p;

    ll l,mid,r;
    ll step = 2 * m->width;
    ll npairs = (m->n + step - 1) / step;

    for (ll i = m->tnum; i < npairs; i += m->colthreads) {
        l = i * step;
        mid = l + m->width;
        r = l + step;

        if (mid >= m->n)
            continue;

        if (r > m->n)
            r = m->n;

        ll f = l, s = mid, g = l;

        while (f < mid && s < r)
            m->buf[g++] = ((m->a[f] <= m->a[s]) ? m->a[f++] : m->a[s++]);
        while (f < mid)
            m->buf[g++] = m->a[f++];
        while (s < r)
            m->buf[g++] = m->a[s++];

        memcpy(m->a + l, m->buf + l, (r - l) * sizeof(int));
    }

    pthread_mutex_lock(&mutex);
    done_count++;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);

    return NULL;
}

int main(int argc, char **argv) {
    int colthreads = 1;
    ll n = 1000000;
    int opt;
    int *a = NULL, *buf = NULL;
    struct timespec t0, t1;

    while ((opt = getopt(argc, argv, "t:n:b:")) != -1) {
        if (opt == 't')
            colthreads = atoi(optarg);
        if (opt == 'n')
            n = atol(optarg);
        if (opt == 'b')
            block_size = atoi(optarg);
    }

    a = malloc(n * sizeof(int));
    buf = malloc(n * sizeof(int));

    for (ll i = 0; i < n; i++)
        a[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &t0);

    for (int i = 0; i < colthreads; i++) {
        sarg sa = (sarg){a, n, i, colthreads};
        pthread_t th;
        pthread_create(&th, NULL, sort_blocks, &sa);
        pthread_detach(th);
    }

    //waiting
    pthread_mutex_lock(&mutex);
    while (done_count < colthreads)
        pthread_cond_wait(&cond, &mutex);
    done_count = 0;
    pthread_mutex_unlock(&mutex);

    for (ll w = block_size; w < n; w *= 2) {
        ll step = 2 * w;
        ll npairs = (n + step - 1) / step;
        int active = ((npairs < colthreads) ? npairs : colthreads);

        for (int i = 0; i < active; i++) {
            marg ma = (marg){a, buf, n, w, i, active};
            pthread_t th;
            pthread_create(&th, NULL, Merge, &ma);
            pthread_detach(th);
        }

        pthread_mutex_lock(&mutex);
        while (done_count < active)
            pthread_cond_wait(&cond, &mutex);
        done_count = 0;
        pthread_mutex_unlock(&mutex);
    }

    clock_gettime(CLOCK_MONOTONIC, &t1);

    printf("time=%.3f threads=%d n=%lld s\n", (t1.tv_sec - t0.tv_sec) + ((t1.tv_nsec - t0.tv_nsec) / 1000000000.0), colthreads, n);

    free(a);
    free(buf);
    return 0;
}