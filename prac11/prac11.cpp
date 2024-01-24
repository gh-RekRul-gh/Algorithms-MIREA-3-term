#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>

using namespace std;

// Разработать программу, выполняющую следующие функции:
// • ввод данных об n объектах из текстового файла в массив структур (0<n<=50);
// • сортировку массива структур по возрастанию значений одного из полей структуры;
// • вывод данных об объектах на экран в упорядоченном по возрастанию виде;
// • поиск объекта по значению одного из полей;
// • запись упорядоченных данных об объектах в двоичный файл;
// • чтение двоичного файла.
// Алгоритмы чтения файла, сортировки, поиска, вывода данных об объектах и записи
// данных в файл оформить в виде функций. Для поиска элемента в упорядоченном массиве
// использовать бинарный поиск. Текстовый файл создать с помощью любого текстового редактора.
// Задание: Объект - Экзамен (шифр студента, дисциплина, семестр, оценка);
// Поле, по которому происходит упорядочивание и поиск - Шифр студента

struct Grade {
    string cipher;
    string name;
    string surname;
    string patronymic;
    string group;
    int mark;
};

void fillGrades(vector<Grade>& array) {
    ifstream fin("Тест.txt");
    int n = 3;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        Grade gr = Grade();
        fin >> gr.cipher >> gr.name >> gr.surname >> gr.patronymic >> gr.group >> gr.mark;
        array.push_back(gr);
    }
    fin.close();
}

void sortGrades(vector<Grade>& array) {
    sort(array.begin(), array.end(), [](Grade& e1, Grade& e2) {
        return e1.cipher < e2.cipher;
        });
}

void printGrades(vector<Grade>& array) {
    for (int i = 0; i < array.size(); ++i) {
        cout << i + 1 << ". " << array[i].cipher << ' ' << array[i].name << ' ' << array[i].surname
            << ' ' << array[i].patronymic << ' ' << array[i].group << ' ' << array[i].mark << endl;
    }
}

void findGradeWithCipher(vector<Grade>& array, string& cipher) {
    int index = 0, len = array.size();
    while (index < len - 1) {
        int mid = (index + len) / 2;
        if (array[mid].cipher > cipher)
            len = mid;
        else
            index = mid;
    }
    if (array[index].cipher != cipher)
        cout << "Студента с таким шифром не найдено\n";
    else
        cout << "Найдена успеваимость студента: " << array[index].cipher << ' ' << array[index].name << ' ' << array[index].surname
        << ' ' << array[index].patronymic << ' ' << array[index].group << ' ' << array[index].mark << endl;
}

void printGradeToBinFile(vector<Grade>& array) {
    ofstream fout("binfile.bin", std::ios::binary);
    int n = array.size();
    fout.write(reinterpret_cast<char*>(&n), sizeof(n));
    for (Grade& item : array) {
        int cipherSize = item.cipher.size() + 1;
        fout.write(reinterpret_cast<char*>(&cipherSize), sizeof(cipherSize));
        fout.write(item.cipher.c_str(), cipherSize);
        int nameSize = item.name.size() + 1;
        fout.write(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        fout.write(item.name.c_str(), nameSize);
        int surnameSize = item.surname.size() + 1;
        fout.write(reinterpret_cast<char*>(&surnameSize), sizeof(surnameSize));
        fout.write(item.surname.c_str(), surnameSize);
        int patrSize = item.patronymic.size() + 1;
        fout.write(reinterpret_cast<char*>(&patrSize), sizeof(patrSize));
        fout.write(item.patronymic.c_str(), patrSize);
        int groupSize = item.group.size() + 1;
        fout.write(reinterpret_cast<char*>(&groupSize), sizeof(groupSize));
        fout.write(item.group.c_str(), groupSize);
        fout.write(reinterpret_cast<char*>(&item.mark), sizeof(item.mark));
    }
    fout.close();
}

vector<Grade> readGradeFromBinFile() {
    ifstream fin("binfile.bin", std::ios::binary);
    vector<Grade> answer;
    int n;
    fin.read(reinterpret_cast<char*>(&n), sizeof(n));
    for (int i = 0; i < n; ++i) {
        Grade temp = Grade();
        int cipherSize;
        fin.read(reinterpret_cast<char*>(&cipherSize), sizeof(cipherSize));
        char buffer[256];
        fin.read(buffer, cipherSize);
        temp.cipher = buffer;
        int nameSize;
        fin.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        fin.read(buffer, nameSize);
        temp.name = buffer;
        int surnameSize;
        fin.read(reinterpret_cast<char*>(&surnameSize), sizeof(surnameSize));
        fin.read(buffer, surnameSize);
        temp.surname = buffer;
        int patrSize;
        fin.read(reinterpret_cast<char*>(&patrSize), sizeof(patrSize));
        fin.read(buffer, patrSize);
        temp.patronymic = buffer;
        int groupSize;
        fin.read(reinterpret_cast<char*>(&groupSize), sizeof(groupSize));
        fin.read(buffer, groupSize);
        temp.group = buffer;
        fin.read(reinterpret_cast<char*>(&temp.mark), sizeof(temp.mark));
        answer.push_back(temp);
    }
    fin.close();
    return answer;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Grade> array;
    fillGrades(array);
    cout << "Данные до сортировки:\n";
    printGrades(array);
    sortGrades(array);
    cout << "Данные после сортировки:\n";
    printGrades(array);
    string cipher;
    cout << "Введите шифр для искомого студента\n";
    cin >> cipher;
    findGradeWithCipher(array, cipher);
    printGradeToBinFile(array);
    vector<Grade> newArray = readGradeFromBinFile();
    cout << "Данные из двоичного файла:\n";
    printGrades(newArray);
    return 0;
}
