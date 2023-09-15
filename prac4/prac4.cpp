#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string email;
    char array[1000];
    cout << "Введите почту\n";
    cin >> email;
    int size = email.size();
    email.copy(array, size);
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == '@') {
            if (i == size - 1) {
                cout << "Почта неверна, нет домена";
                return 0;
            }
            else
                break;
        }
        else if (array[i] == '.') {
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
    cout << "Почта верна";
    return 0;
}