#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>
void fillMatrix(vector<vector<T>>& matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Введите элемент матрицы в строке номер " << i + 1 << ", столбце номер " << j + 1 << endl;
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
void printMatrix(vector<vector<T>>& matrix, int n, int m) {
    cout << "Текущая матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

template <typename T>
void sortMatrix(vector<vector<T>>& matrix, int n, int m) {
    cout << "Введите элемент, который будет сортироваться в начало строк матрицы\n";
    T val;
    cin >> val;
    for (int i = 0; i < n; ++i) {
        vector<T> temp(m);
        int right = 0, wrong = 0;
        int counter = 0;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == val)
                counter++;
        }
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == val) {
                temp[right] = val;
                right++;
            }
            else {
                temp[counter + wrong] = matrix[i][j];
                wrong++;
            }
        }
        matrix[i] = temp;
        temp.clear();
    }
    cout << "Матрица отсортирована\n";
}

int main() {
    setlocale(LC_ALL, "");
    int n, m;
    cout << "Введите сначала количество строк матрицы (от 1 до 100), затем количество столбцов (от 1 до 50)\n";
    cin >> n >> m;
    if (n < 1 || n > 100) {
        cout << "Неверное число строк матрицы";
        return 0;
    }
    if (m < 1 || m > 50) {
        cout << "Неверное число столбцов матрицы";
        return 0;
    }
    cout << "Введите тип элементов матрицы (1 - целые числа; 2 - дробные числа; 3 - символы)\n";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        vector<vector<int>> matrix(n, vector<int>(m));
        fillMatrix(matrix, n, m);
        printMatrix(matrix, n, m);
        sortMatrix(matrix, n, m);
        printMatrix(matrix, n, m);
        cout << "Конец работы программы";
        break;
    }
    case 2: {
        vector<vector<float>> matrix(n, vector<float>(m));
        fillMatrix(matrix, n, m);
        printMatrix(matrix, n, m);
        sortMatrix(matrix, n, m);
        printMatrix(matrix, n, m);
        cout << "Конец работы программы";
        break;
    }
    case 3: {
        vector<vector<char>> matrix(n, vector<char>(m));
        fillMatrix(matrix, n, m);
        printMatrix(matrix, n, m);
        sortMatrix(matrix, n, m);
        printMatrix(matrix, n, m);
        cout << "Конец работы программы";
        break;
    }
    default: {
        cout << "Введено неверное значение";
        return 0;
        break;
    }
    }
    return 0;
}
