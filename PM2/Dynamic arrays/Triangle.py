# Среди треугольников с вершинами в заданном множестве точек на плоскости найти такой, 
# стороны которого содержат максимальное количество точек заданного множества.

import math

def points_on_segment(p1, p2, points):
    count = 0
    for p in points:
        if p == p1 or p == p2:
            continue
        x1, y1 = p1
        x2, y2 = p2
        x, y = p
        
        area = abs((x2 - x1) * (y - y1) - (x - x1) * (y2 - y1))
        if area > 0.0001:
            continue
            
        if min(x1, x2) - 0.0001 <= x <= max(x1, x2) + 0.0001 and min(y1, y2) - 0.0001 <= y <= max(y1, y2) + 0.0001:
            count += 1
    return count

def triangle_points_count(triangle, points):
    p1, p2, p3 = triangle
    count = 0
    count += points_on_segment(p1, p2, points)
    count += points_on_segment(p2, p3, points)
    count += points_on_segment(p3, p1, points)
    return count

def find_best_triangle(points):
    if len(points) < 3:
        return None, 0
    
    best_triangle = None
    max_count = -1
    
    n = len(points)
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                triangle = (points[i], points[j], points[k])
                cnt = triangle_points_count(triangle, points)
                if cnt > max_count:
                    max_count = cnt
                    best_triangle = triangle
    
    return best_triangle, max_count

n = int(input("Введите количество точек: "))
points = []
print("Введите координаты точек (x y):")
for i in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

triangle, count = find_best_triangle(points)

if triangle:
    print(f"Лучший треугольник: {triangle}")
    print(f"Стороны содержат {count} точек (включая вершины)")
else:
    print("Недостаточно точек для построения треугольника")