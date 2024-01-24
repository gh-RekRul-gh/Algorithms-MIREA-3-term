#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Разработать программу, которая вводит матрицу из n строк и m столбцов (n<=100, m<=50)
// и упорядочивает элементы матрицы. Правило упорядочивания определяется вариантом.
// Программа должна предоставлять пользователю выбор типа элементов матрицы: целого или строкового.
// Операции ввода, вывода и упорядочивания элементов матрицы должны быть реализованы
// в виде перегруженных функций.
// Задание - Переместить в каждой строке все элементы с заданным значением в начало
// строки, а остальные – в конец

void fillMatrix(vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Введите элемент матрицы в строке номер " << i + 1 << ", столбце номер " << j + 1 << endl;
            cin >> matrix[i][j];
        }
    }
}

void fillMatrix(vector<vector<string>>& matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Введите элемент матрицы в строке номер " << i + 1 << ", столбце номер " << j + 1 << endl;
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(vector<vector<int>>& matrix, int n, int m) {
    cout << "Текущая матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void printMatrix(vector<vector<string>>& matrix, int n, int m) {
    cout << "Текущая матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void sortMatrix(vector<vector<int>>& matrix, int n, int m) {
    cout << "Введите число, которое будет сортироваться в начало строк матрицы\n";
    int val;
    cin >> val;
    for (int i = 0; i < n; ++i) {
        vector<int> temp(m);
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

void sortMatrix(vector<vector<string>>& matrix, int n, int m) {
    cout << "Введите строковое значение, которое будет сортироваться в начало строк матрицы\n";
    string val;
    cin >> val;
    for (int i = 0; i < n; ++i) {
        vector<string> temp(m);
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
    cout << "Введите 1, если хотите заполнять матрицу целыми числами, или 2, если хотите заполнять ее строками\n";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            vector<vector<int>> matrix(n, vector<int>(m));
            fillMatrix(matrix, n, m);
            printMatrix(matrix, n, m);
            sortMatrix(matrix, n, m);
            printMatrix(matrix, n, m);
            break;
        }
        case 2: {
            vector<vector<string>> matrix(n, vector<string>(m));
            fillMatrix(matrix, n, m);
            printMatrix(matrix, n, m);
            sortMatrix(matrix, n, m);
            printMatrix(matrix, n, m);
            break;
        }
        default: {
            cout << "Введено неверное значение";
            return 0;
            break;
        }
    }

    cout << "Конец работы программы";
    return 0;
}
