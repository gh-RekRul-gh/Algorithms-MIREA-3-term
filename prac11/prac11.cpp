#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Exam {
    string cipher;
    string discipline;
    int term;
    int mark;
};

void fillExams(vector<Exam>& arr) {
    ifstream fin("Тест.txt");
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        Exam nextExam = Exam();
        fin >> nextExam.cipher >> nextExam.discipline >> nextExam.term >> nextExam.mark;
        arr.push_back(nextExam);
    }
    fin.close();
    return;
}

void sortExams(vector<Exam>& arr) {
    sort(arr.begin(), arr.end(), [](Exam& e1, Exam& e2) {
        return e1.cipher < e2.cipher;
        });
    return;
}

void printExams(vector<Exam>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Экзамен номер " << i + 1 << ": " << arr[i].cipher << ' ' << arr[i].discipline << ' ' << arr[i].term << ' ' << arr[i].mark << endl;
    }
    return;
}

void findExamWithCipher(vector<Exam>& arr, string& cipher) {
    int le = 0, ri = arr.size();
    while (le < ri - 1) {
        int mid = (le + ri) / 2;
        if (arr[mid].cipher > cipher)
            ri = mid;
        else
            le = mid;
    }
    if (arr[le].cipher != cipher)
        cout << "Экзамен с таким шифром не найден\n";
    else
        cout << "Найден экзамен: " << arr[le].cipher << ' ' << arr[le].discipline << ' ' << arr[le].term << ' ' << arr[le].mark << endl;
}

void printExamsToBinFile(vector<Exam>& arr) {
    ofstream fout("binfile.bin", std::ios::binary);
    int n = arr.size();
    fout.write(reinterpret_cast<char*>(&n), sizeof(n)); 
    for (Exam& item : arr) {
        int cipherSize = item.cipher.size() + 1;
        fout.write(reinterpret_cast<char*>(&cipherSize), sizeof(cipherSize));
        fout.write(item.cipher.c_str(), cipherSize);
        int disciplineSize = item.discipline.size() + 1;
        fout.write(reinterpret_cast<char*>(&disciplineSize), sizeof(disciplineSize));
        fout.write(item.discipline.c_str(), disciplineSize);
        fout.write(reinterpret_cast<char*>(&item.term), sizeof(item.term));
        fout.write(reinterpret_cast<char*>(&item.mark), sizeof(item.mark));
    }
    fout.close();
    return; 
}

     {
    ifstream fin("binfile.bin", std::ios::binary);
    vector<Exam> ans;
    int n;
    fin.read(reinterpret_cast<char*>(&n), sizeof(n)); 
    for (int i = 0; i < n; ++i) {
        Exam temp = Exam();
        int cipherSize;
        fin.read(reinterpret_cast<char*>(&cipherSize), sizeof(cipherSize)); 
        char buffer[256]; 
        fin.read(buffer, cipherSize); 
        temp.cipher = buffer;
        int disciplineSize;
        fin.read(reinterpret_cast<char*>(&disciplineSize), sizeof(disciplineSize));
        fin.read(buffer, disciplineSize);
        temp.discipline = buffer;
        fin.read(reinterpret_cast<char*>(&temp.term), sizeof(temp.term));   
        fin.read(reinterpret_cast<char*>(&temp.mark), sizeof(temp.mark));
        ans.push_back(temp);
    }
    fin.close();
    return ans;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Exam> arr;   
    fillExams(arr);
    cout << "До сортировки:\n";
    printExams(arr);
    sortExams(arr);
    cout << "После сортировки:\n";
    printExams(arr);
    string cipher;
    cout << "Введите шифр для искомого экзамена\n";
    cin >> cipher;
    findExamWithCipher(arr, cipher);
    printExamsToBinFile(arr);
    vector<Exam> newArr = readFromBinFile();
    cout << "Из двоичного файла:\n";
    printExams(newArr);
    return 0;
}
