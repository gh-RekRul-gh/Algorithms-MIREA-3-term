#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Разработать программу, которая вводит адрес электронной почты и
// проверяет синтаксис введенного адреса. Результат проверки выводится в виде сообщения на экран.
// Задание - В имени пользователя могут быть только одиночные точки

int main() {
    setlocale(LC_ALL, "Russian");
    string email;
    cout << "Введите почту\n";
    cin >> email;
    int size = email.size();
    int counter = 0;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (email[i] == '@') {
            found = true;
            if (i == size - 1) {
                cout << "Почта неверна, нет домена";
                return 0;
            }
            else
                break;
        }
        else if (email[i] == '.') {
            if (counter) {
                cout << "Почта неверна, в имени пользователя могут быть только одиночные точки";
                return 0;
            }
            else
                counter++;
        }
        else
            counter = 0;
        
    }
    if (!found)
        cout << "Не почта";
    else 
        cout << "Почта верна";
    return 0;
}