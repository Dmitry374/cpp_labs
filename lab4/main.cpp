//
// Created by dima on 13.03.2020.
//

/*    1. Напишите программу – «телефонную книжку».
Записи (имя и телефон) должны хранится в каком-либо STL-контейнере (vector или list), причем крайне желательно, чтобы от типа контейнера не зависело ничего, кроме одной строки в программе – объявления этого контейнера (указание: используйте typedef).

Программа должна поддерживать следующие операции:
    • Просмотр текущей записи
    • Переход к следующей записи
    • Переход к предыдущей записи
    • Вставка записи перед/после просматриваемой
    • Замена просматриваемой записи
    • Вставка записи в конец базы данных
    • Переход вперед/назад через n записей. */

#include <iostream>
#include <string>
#include "PhoneBook.h"

PhoneBook *phoneBook = new PhoneBook();

void printPhoneBook();

int main()
{
    int pos;

    phoneBook->setPhoneRecord(*new Record("Dad", "+764564898"));
    phoneBook->setPhoneRecord(*new Record("Mum", "+793242349"));
    phoneBook->setPhoneRecord(*new Record("Friend", "+745654644"));

    printPhoneBook();


    cout << " - Просмотр текущей записи" << endl;
    phoneBook->getCurrentRecord();

    cout << " - Переход к следующей записи" << endl;
    phoneBook->getNextRecord();

    cout << endl;

    cout << " - Переход к предыдущей записи" << endl;
    phoneBook->getPrevRecord();

    cout << endl;

    cout << " - Вставка записи после просматриваемой (" << phoneBook->returnCurrentRecord().getName() << "):" << endl;
    phoneBook->insertRecord(*new Record("Dima", "+796347937"), phoneBook->NEXT);
    phoneBook->getCurrentRecord();

    printPhoneBook();

    cout << " - Вставка записи перед просматриваемой (" << phoneBook->returnCurrentRecord().getName() << "):" << endl;
    phoneBook->insertRecord(*new Record("Michail", "+793623424"), phoneBook->PREV);
    phoneBook->getCurrentRecord();

    printPhoneBook();

    cout << " - Замена просматриваемой записи (" << phoneBook->returnCurrentRecord().getName() << "):" << endl;
    phoneBook->replaceCurrentRecord(*new Record("Alex", "+792242573"));
    phoneBook->getCurrentRecord();

    printPhoneBook();

    cout << " - Вставка записи в конец базы данных" << endl;
    phoneBook->insertRecordInBack(*new Record("Olga", "+734432573"));
    phoneBook->getCurrentRecord();

    printPhoneBook();

    pos = 3;
    cout << " - Переход вперед через " << pos << " записи относительно контакта - " << phoneBook->returnCurrentRecord().getName() << endl;
    phoneBook->goForwardOrBack(pos, phoneBook->FORWARD);
    phoneBook->getCurrentRecord();

    pos = 4;
    cout << " - Переход назад через " << pos << " записи относительно контакта - " << phoneBook->returnCurrentRecord().getName() << endl;
    phoneBook->goForwardOrBack(pos, phoneBook->BACK);
    phoneBook->getCurrentRecord();

    cout << " - Переход в начало:" << endl;
    phoneBook->resetMyIterator();
    phoneBook->getCurrentRecord();

}

void printPhoneBook() {
    cout << "----- My phone book -----" << endl;
    phoneBook->printPhoneBook();
    cout << "-------------------------" << endl << endl;
}