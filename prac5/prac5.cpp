#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string text;
    cout << "Введите текст\n";
    getline(cin, text);
    int answer = 0;
    int size = text.size();
    if (isdigit(text[size - 1]) && (text[size - 1] - '0') % 2 == 0)
        answer++;
    for (int i = size - 2; i >= 0; --i) {
        if (isdigit(text[i]) && !isdigit(text[i + 1]) && (text[i] - '0') % 2 == 0)
            answer++;
    }
    cout << "Количество слов, которые являются записью четных чисел, равно " << answer;

    return 0;
}