import math

n = int(input("Введите количество вершин многоугольника: "))

points = []


for i in range(n):
    print(f"\nВершина {i + 1}")
    x = float(input("x = "))
    y = float(input("y = "))
    points.append((x, y))

perimeter = 0

for i in range(n):
    x1, y1 = points[i]
    x2, y2 = points[(i + 1) % n]
    side = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    perimeter += side


print("\nПериметр многоугольника =", perimeter)