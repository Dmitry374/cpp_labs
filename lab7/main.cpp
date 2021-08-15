/*Необходимо выполнить следующее задание:

    1. Разработать функтор, позволяющий собирать статистику о последовательности целых чисел (послед может содержать числа от -500 до 500). Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:
        a. Максимальное число в последовательности
        b. Минимальное число в последовательности
        c. Среднее число в последовательности
        d. Количество положительных чисел
        e. Количество отрицательных чисел
        f. Сумму нечетных элементов последовательности
        g. Сумму четных элементов последовательности
        h. Совпадают ли первый и последний элементы последовательности.

Проверить работу программы на случайно сгенерированных последовательностях.*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#define SIZE 10

using namespace std;

class MyFunctor {
public:

    int max = 0;
    int min = 0;

    double sum = 0;

    int kolPositive = 0;
    int kolNegative = 0;

    int sumOdd = 0; // сумма нечетных
    int sumEven = 0; // сумма четных

    int firstElement = 0;
    int lastElement = 0;

    int pos = 0;

    void operator() (int num) {

        if (num > max) {
            max = num;
        }

        if (num < min) {
            min = num;
        }

        if (num > 0) {
            kolPositive++;
        }

        if (num < 0) {
            kolNegative++;
        }

        sum = sum + num;

        if (num % 2 == 0) {
            sumEven = sumEven + num;
        }

        if (num % 2 != 0) {
            sumOdd = sumOdd + num;
        }

        if (pos == 0) {
            firstElement = num;
        }

        if (pos == SIZE-1) {
            lastElement = num;
        }

        pos++;
    }

    int getMax() {
        return max;
    }

    int getMin() {
        return min;
    }

    double getAverage() {
        return sum / SIZE;
    }

    int getKolPositive() {
        return kolPositive;
    }

    int getKolNegative() {
        return kolNegative;
    }

    int getSumEven() {
        return sumEven;
    }

    int getSumOdd() {
        return sumOdd;
    }

    int getFirstElement() {
        return firstElement;
    }

    int getLastElement() {
        return lastElement;
    }

    bool isEqualFirstAndLastElement() {
        return getFirstElement() == getLastElement();
    }
};

vector<int> vectorNumbers;

void fillVectorRandom();

void printVector();

void print_elem(int);

int main() {

    MyFunctor myFunctor;

    fillVectorRandom();

    printVector();

    myFunctor = for_each(vectorNumbers.begin(), vectorNumbers.end(), myFunctor);

    cout << endl;

    cout << "Максимальное число в последовательности: " << myFunctor.getMax() << endl;

    cout << "Минимальное число в последовательности: " << myFunctor.getMin() << endl;

    cout << "Среднее число в последовательности: " << myFunctor.getAverage() << endl;

    cout << "Количество положительных чисел: " << myFunctor.getKolPositive() << endl;

    cout << "Количество отрицательных чисел: " << myFunctor.getKolNegative() << endl;

    cout << "Сумму нечетных элементов последовательности: " << myFunctor.getSumOdd() << endl;

    cout << "Сумму четных элементов последовательности: " << myFunctor.getSumEven() << endl;

    cout << "Совпадают ли первый и последний элементы последовательности: " << (myFunctor.isEqualFirstAndLastElement() ? "Да" : "Нет") << endl;

}

void fillVectorRandom() {
    srand((unsigned) time(0));
    for (int i = 0; i < SIZE; i++) {
        int num = random()%1000 - 500;
        vectorNumbers.push_back(num);
    }
}

void printVector() {
    cout << "-----------------------------------------------" << endl;
    for_each(vectorNumbers.begin(), vectorNumbers.end(), print_elem);
    cout << endl << "-----------------------------------------------" << endl;
}

void print_elem(int num) {
    cout << num << " ";
}

