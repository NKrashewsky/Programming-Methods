#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int a, b, c, max_side, square_sum;
    setlocale(LC_ALL, "");
    cout << "Введите стороны треугольника: ";
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Треугольника не существует";
        return 0;
    }
    if (a == b && a == c) {
        cout << "Треугольник равносторонний";
        return 0;
    }
    if (a == b || a == c) {
        cout << "Треугольник равнобедренный";
        return 0;
    }
    max_side = max(a, b);
    max_side = max(max_side, c);
    max_side = max_side * max_side;
    square_sum = a * a + b * b + c * c - max_side;

    if (square_sum > max_side) {
        cout << "Треугольник остроугольный";
    }
    else if (square_sum == max_side) {
        cout << "Треугольник прямоугольный";
    }
    else 
        cout << "Треугольник тупоугольный";

    
    return 0;
}
