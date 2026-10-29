# Лабораторные работы №3  Вариант 4

## Цель работы

Целью является приобретение практических навыков в:

·     Управление потоками в ОС

·     Обеспечение синхронизации между потоками

## Задание
Составить программу на языке Си, обрабатывающую данные в многопоточном режиме. При обработки использовать стандартные средства создания потоков операционной системы . Ограничение максимального количества потоков, работающих в один момент времени, должно быть задано ключом запуска вашей программы.

Так же необходимо уметь продемонстрировать количество потоков, используемое вашей программой с помощью стандартных средств операционной системы.

В отчете привести исследование зависимости ускорения и эффективности алгоритма от входных данных и количества потоков. Получившиеся результаты необходимо объяснить.

4 вариант: Отсортировать массив целых чисел при помощи TimSort.

eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 4 -n 1000000
threads=4 n=1000000 time=0.0519 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 16 -n 1000000
threads=16 n=1000000 time=0.0540 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 24 -n 1000000
threads=24 n=1000000 time=0.0562 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 2 -n 1000000
threads=2 n=1000000 time=0.0749 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 1 -n 1000000
threads=1 n=1000000 time=0.1297 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 3 -n 1000000
threads=3 n=1000000 time=0.0563 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 5 -n 1000000
threads=5 n=1000000 time=0.0482 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 6 -n 1000000
threads=6 n=1000000 time=0.0456 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 8 -n 1000000
threads=8 n=1000000 time=0.0404 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 12 -n 1000000
threads=12 n=1000000 time=0.0426 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 10 -n 1000000
threads=10 n=1000000 time=0.0407 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 9 -n 1000000
threads=9 n=1000000 time=0.0410 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 8 -n 1000000
threads=8 n=1000000 time=0.0433 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 8 -n 1000000
threads=8 n=1000000 time=0.0408 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 8 -n 1000000
threads=8 n=1000000 time=0.0413 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 8 -n 100
threads=8 n=100 time=0.0005 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 1 -n 100
threads=1 n=100 time=0.0004 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 1 -n 100
threads=1 n=100 time=0.0004 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 1 -n 100
threads=1 n=100 time=0.0004 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 1 -n 100
threads=1 n=100 time=0.0004 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 10 -n 100
threads=10 n=100 time=0.0007 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 10 -n 100
threads=10 n=100 time=0.0008 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 10 -n 100
threads=10 n=100 time=0.0007 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$ ./lab_os_3 -t 100 -n 100
threads=100 n=100 time=0.0052 s
eonid@LEOBOOK:/mnt/c/Users/Leonid/CLionProjects/lab_os_3/build$