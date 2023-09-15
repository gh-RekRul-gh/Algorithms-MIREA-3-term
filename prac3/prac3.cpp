#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите сначала количество строк матрицы (от 2 до 100), затем количество столбцов (от 2 до 50)\n";
    cin >> n >> m;
    if (n < 2 || n > 100) {
        cout << "Введено неверное значение числа строк матрицы";
        return 0;
    }
    if (m < 2 || m > 50) {
        cout << "Введено неверное значение числа столбцов матрицы";
        return 0;
    }
    int array[100][50] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "Введите число матрицы в " << i + 1 << " строке, " << j + 1 << " столбце\n";
            cin >> array[i][j];
        }
    }
    int b[50] = {};
    cout << "Введите " << m << " чисел, которыми будет заменяться пустая строка в массиве\n";
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        bool notZero = false;
        for (int j = 0; j < m; ++j) {
            if (array[i][j] != 0) {
                notZero = true;
                break;
            }
        }
        if (!notZero) {
            for (int j = 0; j < m; ++j) {
                array[i][j] = b[j];
            }
        }
    }
    cout << "Готовая матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << array[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}