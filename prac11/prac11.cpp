//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//#include <algorithm>
//#include <windows.h>
//
//using namespace std;
//
//struct Exam {
//    string cipher;
//    string discipline;
//    int term;
//    int mark;
//};
//
//void fillExams(vector<Exam>& arr) {
//    ifstream fin("Тест.txt");
//    int n;
//    fin >> n;
//    for (int i = 0; i < n; ++i) {
//        Exam nextExam = Exam();
//        fin >> nextExam.cipher >> nextExam.discipline >> nextExam.term >> nextExam.mark;
//        arr.push_back(nextExam);
//    }
//    fin.close();
//    return;
//}
//
//void sortExams(vector<Exam>& arr) {
//    sort(arr.begin(), arr.end(), [](Exam& e1, Exam& e2) {
//        return e1.cipher < e2.cipher;
//        });
//    return;
//}
//
//void printExams(vector<Exam>& arr) {
//    for (int i = 0; i < arr.size(); ++i) {
//        cout << "Экзамен номер " << i + 1 << ": " << arr[i].cipher << ' ' << arr[i].discipline << ' ' << arr[i].term << ' ' << arr[i].mark << endl;
//    }
//    return;
//}
//
//void findExamWithCipher(vector<Exam>& arr, string& cipher) {
//    int le = 0, ri = arr.size();
//    while (le < ri - 1) {
//        int mid = (le + ri) / 2;
//        if (arr[mid].cipher > cipher)
//            ri = mid;
//        else
//            le = mid;
//    }
//    if (arr[le].cipher != cipher)
//        cout << "Экзамен с таким шифром не найден\n";
//    else
//        cout << "Найден экзамен: " << arr[le].cipher << ' ' << arr[le].discipline << ' ' << arr[le].term << ' ' << arr[le].mark << endl;
//}
//
//void printExamsToBinFile(vector<Exam>& arr) {
//    ofstream fout("binfile.bin", std::ios::binary);
//    int n = arr.size();
//    fout.write(reinterpret_cast<char*>(&n), sizeof(n)); 
//    for (Exam& item : arr) {
//        int cipherSize = item.cipher.size() + 1;
//        fout.write(reinterpret_cast<char*>(&cipherSize), sizeof(cipherSize));
//        fout.write(item.cipher.c_str(), cipherSize);
//        int disciplineSize = item.discipline.size() + 1;
//        fout.write(reinterpret_cast<char*>(&disciplineSize), sizeof(disciplineSize));
//        fout.write(item.discipline.c_str(), disciplineSize);
//        fout.write(reinterpret_cast<char*>(&item.term), sizeof(item.term));
//        fout.write(reinterpret_cast<char*>(&item.mark), sizeof(item.mark));
//    }
//    fout.close();
//    return; 
//}
//
//     {
//    ifstream fin("binfile.bin", std::ios::binary);
//    vector<Exam> ans;
//    int n;
//    fin.read(reinterpret_cast<char*>(&n), sizeof(n)); 
//    for (int i = 0; i < n; ++i) {
//        Exam temp = Exam();
//        int cipherSize;
//        fin.read(reinterpret_cast<char*>(&cipherSize), sizeof(cipherSize)); 
//        char buffer[256]; 
//        fin.read(buffer, cipherSize); 
//        temp.cipher = buffer;
//        int disciplineSize;
//        fin.read(reinterpret_cast<char*>(&disciplineSize), sizeof(disciplineSize));
//        fin.read(buffer, disciplineSize);
//        temp.discipline = buffer;
//        fin.read(reinterpret_cast<char*>(&temp.term), sizeof(temp.term));   
//        fin.read(reinterpret_cast<char*>(&temp.mark), sizeof(temp.mark));
//        ans.push_back(temp);
//    }
//    fin.close();
//    return ans;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    vector<Exam> arr;   
//    fillExams(arr);
//    cout << "До сортировки:\n";
//    printExams(arr);
//    sortExams(arr);
//    cout << "После сортировки:\n";
//    printExams(arr);
//    string cipher;
//    cout << "Введите шифр для искомого экзамена\n";
//    cin >> cipher;
//    findExamWithCipher(arr, cipher);
//    printExamsToBinFile(arr);
//    vector<Exam> newArr = readFromBinFile();
//    cout << "Из двоичного файла:\n";
//    printExams(newArr);
//    return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>

using namespace std;

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
