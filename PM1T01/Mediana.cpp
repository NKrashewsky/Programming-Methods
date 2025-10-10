#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    const int n = 5;
    int  arr[n], mem, i, j;
    cout << "Введите " << n << " чисел:\n";
    for (i = 0; i < 5; i++) {
        cin >> arr[i];     
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                mem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = mem;
            }
        }
    }
    cout << arr[2];
}

