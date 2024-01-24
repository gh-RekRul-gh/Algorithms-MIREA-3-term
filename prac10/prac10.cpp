#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// Разработать программу, использующую рекурсивную функцию для выполнения задания.
// Задание - Вывод на экран строки в обратном порядке

void printReversedString(string& str, int cur) {
    if (cur == str.size() - 1) {
        cout << str[cur];
        return;
    }
    printReversedString(str, cur + 1);
    cout << str[cur];
    return;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Enter a string\n";
    getline(cin, str);
    cout << "Reversed given string:\n";
    printReversedString(str, 0);
    return 0;
}
