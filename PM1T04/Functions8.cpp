//	Найти n-ый член геометрической прогрессии с заданным первым членом b и знаменателем прогрессии q
#include <iostream>
#include <cmath>
using namespace std;

bool isValidNatural(int n) {
    return n > 0;
}

double geometricTerm(double b, double q, int n) {
    return b * pow(q, n - 1);
}

void inputDouble(double& value) {
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода. Повторите: ";
    }
}

void inputNatural(int& value) {
    while (!(cin >> value) || !isValidNatural(value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода. Введите натуральное число: ";
    }
}

int main() {
    double b, q;
    int n;

    cout << "Введите первый член прогрессии b: ";
    inputDouble(b);

    cout << "Введите знаменатель прогрессии q: ";
    inputDouble(q);

    cout << "Введите номер члена n: ";
    inputNatural(n);

    double result = geometricTerm(b, q, n);
    cout << "n-й член геометрической прогрессии: " << result << endl;

    return 0;
}
