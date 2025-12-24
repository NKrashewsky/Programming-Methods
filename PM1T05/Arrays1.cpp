// Дана матрица, каждая строка состоит из символов строчного английского алфавита. Найти и вывести те строки, в которых символы расположены в алфавитном порядке. Найти и вывести столбцы, являющиеся палиндромами (читаются сверху вниз и снизу вверх одинаково)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    
    for (int i = 0; i < n; ++i)
        cin >> matrix[i];

    cout << "Строки в алфавитном порядке:\n";
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] < matrix[i][j-1]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << matrix[i] << endl;
    }

    cout << "Столбцы-палиндромы:\n";
    for (int j = 0; j < m; ++j) {
        bool ok = true;
        for (int i = 0; i < n/2; ++i) {
            if (matrix[i][j] != matrix[n-1-i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n; ++i)
                cout << matrix[i][j];
            cout << endl;
        }
    }

    return 0;
}
