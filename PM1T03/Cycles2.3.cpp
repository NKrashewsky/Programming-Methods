//3. Бактерия делится каждые 3 часа. Определить, сколько бактерий будет через n часов, если изначально была только одна
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int divisions = n / 3;
    long long bacteria = pow(2, divisions);

    cout << bacteria;
    return 0;
}
