/*  1. Написать программу, которая выполняет следующие действия:
        a. Читает содержимое текстового файла
        b. Выделяет слова, словом считаются последовательность символов разделенных пробелами и/или знаками табуляции и/или символами новой строки
        c. Вывести список слов присутствующий в тексте без повторений (имеется в виду,
        что одно и то же слово может присутствовать в списке только один раз)*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> vec;

void read_file(string&);

void print_string(string&);

void print_vector();

void split(string& str);

void erase_duplicates();

int main() {

    string str;

    read_file(str);

    cout << "Current string:" << endl;
    print_string(str);

    // Разбиваем вектор на слова
    split(str);

    cout << endl;

    cout << "Размер исходного вектора: " << vec.size() << endl;

    // Удаляем повторяющиеся слова в списке
    erase_duplicates();

    cout << endl;

    cout << "--- Вектор после удаления повторяющихся слов --- " << endl;
    print_vector();

    cout << endl;

    cout << "Размер вектора после удаления повторяющихся слов: " << vec.size() << endl;

}

void read_file(string& str) {
    ifstream myfile("../stl_06/turov/6_1/text.txt");          //opening the file.

    myfile.seekg(0, ios::end);
    str.reserve(myfile.tellg());
    myfile.seekg(0, ios::beg);

    str.assign((istreambuf_iterator<char>(myfile)),
               istreambuf_iterator<char>());
}

void print_string(string& str) {
    cout << str << "\n" << endl;
}

void print_vector() {
    for (vector<string>::iterator i = vec.begin(); i != vec.end(); i++) {
        cout << *i << endl;
    }
}

void split(string& str) {

    string result;

    remove_copy_if(str.begin(), str.end(),
                   std::back_inserter(result), //Store output
                   std::ptr_fun<int, int>(&std::ispunct)
    );

    stringstream ss(result);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);

    cout << "--- Вектор слов ---" << endl;
    copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    vec = vstrings;
}

void erase_duplicates() {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}