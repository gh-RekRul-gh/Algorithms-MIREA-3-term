#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <windows.h>

using namespace std;

int find_in_vector(char elem, vector<char>& vect, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (elem == vect[i]) return i;
    }
    return -1;
}

string convTo10(string num, int cur_base) {
    int x = 0;
    for (int i = 0; i < num.size(); ++i) {
        if (isdigit(num[i]))
            x = (x * cur_base) + (num[i] - '0');
        else
            x = (x * cur_base) + ((num[i] - 'A') + 10);
    }
    return to_string(x);
}

string convFrom10(string num, int res_base, vector<char> &symbols) {
    long long x = stoi(num);
    vector<char> v;
    while(x != 0) {
        v.push_back(symbols[x % res_base]);
        x = x / res_base;
    }
    string ans = "";
    for (int i = v.size() - 1; i >= 0; --i) { ans += v[i]; }
    return ans;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string num;
    int q, p;
    vector<char> symbols = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'F', 'E' };
    int symbols_size = symbols.size();
    cout << "Enter the number system of the entered number from 2 to 16\n";
    cin >> q;
    if (q < 2 || q > 16) {
        cout << "Wrong input, number system not in 2-16 range";
        return 0;
    }
    cout << "Enter the number you want to convert\n";
    cin >> num;
    for (int i = 0; i < num.size(); ++i) {
        if (find_in_vector(num[i], symbols, 0, q) == -1) {
            cout << "Wrong input, not a number or number doesn't exist in this number system";
            return 0;
        }
    }
    cout << "Enter the number system you want to convert to from 2 to 16\n";
    cin >> p;
    if (p < 2 || p > 16) {
        cout << "Wrong input, number system not in 2-16 range";
        return 0;
    }
    if (q == p)
        cout << "The entered number systems are equal, the result is " << num << "\n";
    else {
        num = convTo10(num, q);
        if (p != 10)
            num = convFrom10(num, p, symbols);
        cout << "The result is " << num;
    }
    return 0;
}
