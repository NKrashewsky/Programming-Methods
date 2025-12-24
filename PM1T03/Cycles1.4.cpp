//4. Введены 2 натуральных числа. Проверить, имеют ли они хотя бы два общих множителя, кроме единицы
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    int x = a, y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    int gcd = x;

    if (gcd > 1 && !isPrime(gcd))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}