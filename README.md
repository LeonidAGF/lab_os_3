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

## О том как на время выпонения влияет количесво потоков и размер сортируемых данных:

threads 4 col of elements in array 1000000 time=0.0519 s

threads 16 col of elements in array 1000000 time=0.0540 s

threads 24 col of elements in array 1000000 time=0.0562 s

threads 2 col of elements in array 1000000 time=0.0749 s

threads 1 col of elements in array 1000000 time=0.1297 s

threads 3 col of elements in array 1000000 time=0.0563 s

threads 5 col of elements in array 1000000 time=0.0482 s

threads 6 col of elements in array 1000000 time=0.0456 s

threads 8 col of elements in array 1000000 time=0.0404 s

threads 12 col of elements in array 1000000 time=0.0426 s

threads 10 col of elements in array 1000000 time=0.0407 s

threads 9 col of elements in array 1000000 time=0.0410 s

threads 8 col of elements in array 1000000 time=0.0433 s

threads 8 col of elements in array 1000000 time=0.0408 s

threads 8 col of elements in array 1000000 time=0.0413 s

threads 8 col of elements in array 100 time=0.0005 s

threads 1 col of elements in array 100 time=0.0004 s

threads 1 col of elements in array 100 time=0.0004 s

threads 1 col of elements in array 100 time=0.0004 s

threads 1 col of elements in array 100 time=0.0004 s

threads 10 col of elements in array 100 time=0.0007 s

threads 10 col of elements in array 100 time=0.0008 s

threads 10 col of elements in array 100 time=0.0007 s

threads 100 col of elements in array 100 time=0.0052 s

###Выводы

Чем больше элементов нужно отсортировать тем больше нужно потоков, но при слишком большом количестве потоков время сортировки начинает замедляться.
Пример: при 1000000 элементов быстрее всего сортировка произошла на 8 потоках, медлееннее всего на 1. Увеличение 8 потоков в 3 раза повысило время выполнения более чем на 0.1 секунды.