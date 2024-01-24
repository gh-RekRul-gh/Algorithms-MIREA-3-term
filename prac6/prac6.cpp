#include <iostream>
#include <string>

using namespace std;

// Дан текст, состоящий из слов, которые разделены пробелами и (или) знаками препинания:
// точкой, запятой, точкой с запятой, тире, двоеточием, кавычками, вопросительным знаком,
// восклицательным знаком, круглыми скобками. Реализовать операцию обработки текста.
// Задание - Найти количество слов, которые являются записью четных чисел
// (числа заданы последовательностью цифр).

long long multi(int* array, int n) {
    if (n == 1) {
        cout << "В массиве всего 1 элемент, элементов с нечетными индексами нет\n";
        return -1;
    }
    long long ans = array[1];
    for (int i = 3; i < n; i += 2) {
        ans *= array[i];
    }
    return ans;
}

pair<int*, bool> del(int* array, int n) {
    if (n == 1) {
        cout << "Длинна массива уже равна 1, удалить элемент нельзя\n";
        return make_pair(array, false);
    }
    int maxElem = array[0];
    int ind = 0;
    for (int i = 1; i < n; ++i) {
        if (array[i] >= maxElem) {
            maxElem = array[i];
            ind = i;
        }
    }
    if (ind == n - 1) {
        cout << "В массиве нет чисел после последнего максимального числа\n";
        return make_pair(array, false);
    }
    ind++;
    int* newArray = new int[n - 1];
    for (int i = 0; i < n; ++i) {
        if (i < ind)
            newArray[i] = array[i];
        else if (i > ind)
            newArray[i - 1] = array[i];
    }
    return make_pair(newArray, true);
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите размер массива от 1 до 100\n";
    int n; 
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Введено неверное значение размера массива";
        return 0;
    }
    int *array = new int[n];
    cout << "Введите " << n << " элементов массива\n";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    string s;
    cout << "Введите \"multiply\", если хотите получить произведение элементов массива с нечетными номерами,\n"
        "введите \"delete\", если хотите удалить элемент после помледнего максимального элемента массива и\n"
        "введите \"exit\", если хотите завершить работу программы\n";
    cin >> s;
    while (s != "exit") {
        if (s == "multiply")
            cout << "Результат перемножения элементов массива с нечетными номерами равен " << multi(array, n) << endl;
        else if (s == "delete") {
            pair<int*, int> result = del(array, n);
            if (result.second) {
                n--;
                array = result.first;
                cout << "Элемент после последнего максимального элемента массива удален\n";
                cout << "Теперь массив выглядит так:\n";
                for (int i = 0; i < n; ++i) {
                    cout << array[i] << ' ';
                }
                cout << endl;
            }
        }
        else
            cout << "Введена непонятная команда\n";
        cin >> s;
    }
    return 0;
}