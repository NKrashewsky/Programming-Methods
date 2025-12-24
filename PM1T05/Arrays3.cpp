//Чтобы визуализировать поведение трехмерного объекта при рендеринге (например, спецэффектов или графики в компьютерных играх), требуется провести вычисления со строками и столбцами пикселей. Эти вычисления включают в себя и поиск ранга. Написать программу для определения ранга матрицы. Матрицу сгенерировать.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<vector<int>> generateMatrix(int rows, int cols, int maxVal = 10) {
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            mat[i][j] = rand() % (maxVal + 1); 
    return mat;
}

int rankMatrix(vector<vector<int>> mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    int rank = 0;

    vector<bool> rowSelected(rows, false);

    for (int i = 0; i < cols; ++i) {
        int j;
        for (j = 0; j < rows; ++j)
            if (!rowSelected[j] && mat[j][i] != 0)
                break;

        if (j != rows) {
            rank++;
            rowSelected[j] = true;
            for (int p = 0; p < rows; ++p) {
                if (p != j && mat[p][i] != 0) {
                    int factor = mat[p][i] / mat[j][i];
                    for (int k = i; k < cols; ++k)
                        mat[p][k] -= factor * mat[j][k];
                }
            }
        }
    }

    return rank;
}

int main() {
    srand(time(0));

    int rows = 4; 
    int cols = 5; 

    vector<vector<int>> mat = generateMatrix(rows, cols);

    cout << "Сгенерированная матрица:\n";
    for (auto &row : mat) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }

    cout << "\nРанг матрицы: " << rankMatrix(mat) << endl;

    return 0;
}
