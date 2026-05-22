#Найти расстояние между двумя заданными множествами точек на плоскости,
# то есть расстояние между наиболее близко расположенными точками этих множеств.

import math

def distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)

def min_distance_between_sets(set1, set2):
    min_dist = float('inf')
    
    for p1 in set1:
        for p2 in set2:
            dist = distance(p1, p2)
            if dist < min_dist:
                min_dist = dist
                
    return min_dist

n1 = int(input("Введите количество точек в первом множестве: "))
set1 = []
print("Введите координаты точек первого множества (x y):")
for i in range(n1):
    x, y = map(int, input().split())
    set1.append((x, y))

n2 = int(input("Введите количество точек во втором множестве: "))
set2 = []
print("Введите координаты точек второго множества (x y):")
for i in range(n2):
    x, y = map(int, input().split())
    set2.append((x, y))

result = min_distance_between_sets(set1, set2)
print(f"Минимальное расстояние между множествами: {result:.4f}")