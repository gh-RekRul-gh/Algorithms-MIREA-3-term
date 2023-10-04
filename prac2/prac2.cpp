#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int array[100] = {0};
    cout << "Введите размер массива от 1 до 100\n";
    int n;
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Введено неверное значение размера массива";
        return 0;
    }
    cout << "Введите " << n << " целочисленных элементов массива\n";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    int minElem = array[0], maxElem = array[0];
    for (int i = 1; i < n; ++i) {
        minElem = min(minElem, array[i]);
        maxElem = max(maxElem, array[i]);
    }
    int answer = 0;
    for (int i = minElem + 1; i < maxElem; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (array[j] == i) {
                found = true;
                break;
            }
        }
        if (!found)
            answer++;
    }
    cout << answer << " чисел из диапазона [min, max] не входят в заданный массив";
    return 0;
}