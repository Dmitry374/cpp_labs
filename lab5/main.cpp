/*    1. Написать программа, которая выполняет следующие действия:

        a. Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
        b. Выводит полученный вектор на печать
        c. Сортирует вектор следующим образом:
            i. По возрастанию key1
            ii. Если key1 одинаковые, то по возрастанию key2
            iii. Если key1 и key2 одинаковые, то по возрастанию длинны строки str
        d. Выводит полученный вектор на печать

DataStruct определена следующим образом:
typedef struct
{
    int       key1;
    int       key2;
    string  str;
} DataStruct; */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

#define SIZE 10

using namespace std;

struct DataStruct {
    int key1;
    int key2;
    string str;

    friend ostream &operator<<(ostream &out, const DataStruct &dataStruct) {
        out << dataStruct.key1 << "\t" << dataStruct.key2 << "\t " << dataStruct.str;
        return out;
    }
};

vector<DataStruct> dataStructVector;
vector<string> strVector;

void fillStructRandom();

void fillStrVector();

void printVectorDataStruct();

void sortVector();

bool compare(const DataStruct&, const DataStruct&);

int main() {

    fillStrVector();

    fillStructRandom();

    cout << "Вектор:" << endl;
    printVectorDataStruct();

    sortVector();

    cout << endl;
    cout << "Отсортироаванный вектор:" << endl;
    printVectorDataStruct();


}

void fillStructRandom() {
    srand((unsigned) time(0));
    for (int i = 0; i < SIZE; i++) {
        DataStruct dataStruct;
        dataStruct.key1 = random()%11 - 5;
        dataStruct.key2 = random()%11 - 5;
        dataStruct.str = strVector[random() % 10];

        dataStructVector.push_back(dataStruct);
    }
}

void fillStrVector() {
    for (int i = 1; i <= SIZE; i++) {
        strVector.push_back("str" + to_string(i * (random()%10000)));
    }
}

void printVectorDataStruct() {
    for (int i = 0; i < dataStructVector.size(); i++) {
        cout << dataStructVector[i] << endl;
    }
}

void sortVector() {
    sort(dataStructVector.begin(), dataStructVector.end(), compare);
}

bool compare(const DataStruct &first, const DataStruct &second) {
    if (first.key1 == second.key1) {
        return first.key2 < second.key2;
    } else if (first.key1 == second.key2) {
        return first.str.size() < second.str.size();
    } else {
        return first.key1 < second.key1;
    }
}