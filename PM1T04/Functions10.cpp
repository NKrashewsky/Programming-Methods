//По схеме Горнера подсчитать значение многочлена степени n в точке x. Коэффициенты многочлена случайные
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isNatural(int n) {
    return n > 0;
}

void inputNatural(int& n) {
    while (!(cin >> n) || !isNatural(n)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода. Введите натуральное число: ";
    }
}

void inputDouble(double& x) {
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода. Повторите: ";
    }
}

int* createCoefficients(int n, int minVal = -5, int maxVal = 5) {
    int* a = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
    return a;
}

double horner(const int* a, int n, double x) {
    double result = a[0];
    for (int i = 1; i <= n; i++) {
        result = result * x + a[i];
    }
    return result;
}

void deleteCoefficients(int*& a) {
    delete[] a;
    a = nullptr;
}

int main() {
    srand((unsigned)time(nullptr));

    int n;
    double x;

    cout << "Введите степень многочлена n: ";
    inputNatural(n);

    cout << "Введите x: ";
    inputDouble(x);

    int* coefficients = createCoefficients(n);

    cout << "Коэффициенты: ";
    for (int i = 0; i <= n; i++) {
        cout << coefficients[i] << " ";
    }
    cout << endl;

    double value = horner(coefficients, n, x);
    cout << "Значение многочлена: " << value << endl;

    deleteCoefficients(coefficients);

    return 0;
}

