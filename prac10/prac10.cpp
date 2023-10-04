#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

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
    setlocale(LC_ALL, "");
    string str;
    cout << "Введите строку\n";
    getline(cin, str);
    cout << "Перевернутая строка:\n";
    printReversedString(str, 0);
    return 0;
}
