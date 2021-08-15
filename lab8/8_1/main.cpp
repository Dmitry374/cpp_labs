/*
    1. Разработать программу, которая, используя только стандартные алгоритмы и функторы, умножает каждый
    элемент списка чисел с плавающей  точкой на число PI*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define SIZE 10

using namespace std;

class MyFunctor {
public:
    void operator() (double &num) {
        num = num * M_PI;
    }
};

vector<double> vectorNumbers;

void fillVectorRandom();

double getRandomDouble(double, double);

void printVector();

void print_elem(double);

int main() {

    MyFunctor myFunctor;

    fillVectorRandom();

    cout << "Исходный вектор:" << endl;

    printVector();

    for_each(vectorNumbers.begin(), vectorNumbers.end(), myFunctor);

    cout << endl;

    cout << "Вектор умноженный на число PI (" << M_PI << "):" << endl;

    printVector();

}

void fillVectorRandom() {
    srand((unsigned) time(0));
    for (int i = 0; i < SIZE; i++) {
        double num = getRandomDouble(0, 20);
        vectorNumbers.push_back(num);
    }
}

double getRandomDouble(double min, double max) {
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

void printVector() {
    cout << "-----------------------------------------------" << endl;
    for_each(vectorNumbers.begin(), vectorNumbers.end(), print_elem);
    cout << endl << "-----------------------------------------------" << endl;
}

void print_elem(double num) {
    cout << setprecision(2) << fixed << num << " ";
}

