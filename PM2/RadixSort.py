# Вам предлагается самостоятельно изучить несколько сортировок, разбившись на команды. Сортировки: слиянием (MergeSort), 
# поразрядная (RadixSort), быстрая с различным выбором опорного элемента (QuickSort).
# Подать сортировке динамический массив случайных чисел и отсортировать.
#  Подсчитать количество элементарных операций (+, *, -, /, взятие по индексу [i]) в каждой сортировке, подсчитать количество вставок и обменов.
# Выбор опорного элемента: произвольный элемент массива, 
# среднее между двумя элементами посередине, среднее первого и последнего элементов, минимум из первого и последнего.

import random

def radix_sort(arr):
    operations = 0
    swaps = 0
    insertions = 0

    if len(arr) == 0:
        return arr, operations, swaps, insertions

    max_val = arr[0]
    for i in range(1, len(arr)):
        operations += 1
        if arr[i] > max_val:
            max_val = arr[i]
    operations += 1

    max_digits = len(str(abs(max_val)))
    operations += 1

    output = arr[:]
    insertions += len(arr)

    exp = 1
    for _ in range(max_digits):
        buckets = [[] for _ in range(10)]
        operations += 10

        for num in output:
            digit = (num // exp) % 10
            operations += 2
            buckets[digit].append(num)
            operations += 1
            insertions += 1

        output = []
        insertions += 1
        for bucket in buckets:
            operations += 1
            for val in bucket:
                output.append(val)
                operations += 1
                insertions += 1

        exp *= 10
        operations += 1

    swaps = 0
    return output, operations, swaps, insertions

n = int(input("Введите размер массива: "))
arr = [random.randint(-1000, 1000) for _ in range(n)]

print("Исходный массив:")
print(arr)

sorted_arr, ops, swaps, inserts = radix_sort(arr.copy())

print("\nОтсортированный массив:")
print(sorted_arr)
print(f"\nЭлементарных операций (+, -, *, /, [i]): {ops}")
print(f"Обменов: {swaps}")
print(f"Вставок: {inserts}")