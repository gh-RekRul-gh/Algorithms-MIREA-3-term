#include <iostream>
#include <cmath>

using namespace std;

double f(double x, int k) {
    return pow(x, k) / exp(x);
}

double integrate(int k, double a, double b, double precision) {
    int n = 1;
    double integral = 0;
    double prevIntegral; 
    do {
        prevIntegral = integral;
        double h = (b - a) / n;
        for (int i = 0; i < n; i++) {
            double curSt = a + i * h;
            double z = h / 3;
            double x1 = curSt;
            double x2 = x1 + z;
            double x3 = x2 + z;
            double x4 = x3 + z;
            integral += (3 * z / 8) * (f(x1, k) + 3 * f(x2, k) + 3 * f(x3, k) + f(x4, k));
        }
        n *= 2;
    } while (abs(integral - prevIntegral) >= precision);
    return integral;
}

int main() {
    setlocale(LC_ALL, "");
    cout << "Вычисление определенного интеграла методом Ньютона-Котеса (m=3) \nдля функции x^k/(e^x) с параметром k \na = 0, b = 1, k = 1, 2, 3, 4\n";
    double a = 0.0, b = 1.0;
    double precision = 0.1;
    int k = 0;
    cout << "Введите параметр k от 1 до 4\n";
    cin >> k;
    if (k < 1 || k > 4) {
        cout << "Неверный ввод";
        return 0;
    }
    double ans = integrate(k, a, b, precision);
    cout << "Значение интеграла: " << ans;
    return 0;
}
