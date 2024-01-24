#include <iostream>
#include <cmath>

using namespace std;

// Задание - найти, находится ли точка внутри закрашенной области
// Закрашенная область - окружность заданного радиуса
// Притом внутри окружности присутствует квадрат повернутый на 45 градусов
// с заданной длиной стороны

bool in_circle(float x, float y, float radius) {
    if (x * x + y * y <= radius * radius)
        return true;
    return false;
}

bool in_rect(float x, float y, float sideOfRectangle) {
    float halfOfDiagonal = sideOfRectangle * sqrt(2) / 2;
    bool ans = true;
    if (x >= 0 && y >= 0 && y > halfOfDiagonal - x) {
        ans = false;
    }
    else if (x < 0 && y >= 0 && y > halfOfDiagonal + x) {
        ans = false;
    }
    else if (x >= 0 && y < 0 && y < -halfOfDiagonal + x) {
        ans = false;
    }
    else if (y < -halfOfDiagonal - x) {
        ans = false;
    }
    return ans;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите радиуc окружности\n";
    float radius;
    cin >> radius;
    if (radius < 0) {
        cout << "Введен отрицательный радиус\n";
        return 0;
    }
    cout << "Введите сторону квадрата\n";
    float sideOfReactangle;
    cin >> sideOfReactangle;
    if (sideOfReactangle < 0) {
        cout << "Введена отрицательная сторона квадрата\n";
        return 0;
    }
    if (radius <= sideOfReactangle) {
        cout << "Закрашенной области нет, радиус окружности меньше стороны квадрата\n";
        return 0;
    }
    cout << "Введите два числа, x и y - координаты точки\n";
    float x, y;
    cin >> x >> y;
    if (in_circle(x, y, radius) && !in_rect(x, y, sideOfReactangle))
        cout << "Точка принадлежит закрашенной области\n";
    else
        cout << "Точка не принадлежит закрашенной области\n";
    return 0;
}