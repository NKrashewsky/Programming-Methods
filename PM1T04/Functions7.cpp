// Найти n-ый член арифметической прогрессии с заданным первым членом a и разностью прогрессии d
#include <iostream>
using namespace std;

bool isValidNatural(int n) {
    return n > 0;
}

int arithmeticTerm(int a, int d, int n) {
    return a + (n - 1) * d;
}

void inputInt(int& value) {
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода. Повторите: ";
    }
}

int main() {
    int a, d, n;

    cout << "Введите первый член прогрессии a: ";
    inputInt(a);

    cout << "Введите разность прогрессии d: ";
    inputInt(d);

    cout << "Введите номер члена n (натуральное число): ";
    inputInt(n);

    if (!isValidNatural(n)) {
        cout << "Ошибка: n должно быть натуральным числом." << endl;
        return 1;
    }

    int result = arithmeticTerm(a, d, n);
    cout << "n-й член арифметической прогрессии: " << result << endl;

    return 0;
}
