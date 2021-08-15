//
// Created by dima on 13.03.2020.
//

#include "PhoneBook.h"

using namespace std;

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

void PhoneBook::printPhoneBook() {
    for (auto i = list_phone_book.begin(); i != list_phone_book.end(); i++) {
        cout << *i;
    }
}

void PhoneBook::resetMyIterator() {
    iterator_current_record = list_phone_book.begin();
}

void PhoneBook::setPhoneRecord(Record &record) {

    if (list_phone_book.empty()) {
        iterator_current_record = list_phone_book.begin();
    }

    list_phone_book.push_back(record);
    iterator_current_record++;
}

void PhoneBook::getCurrentRecord() {
    cout << "Текущая запись - " << *iterator_current_record << endl;
}

Record& PhoneBook::returnCurrentRecord() {
    Record &record = *iterator_current_record;
    return *&record;
}

void PhoneBook::getNextRecord() {
    iterator_current_record++;

    if (iterator_current_record == list_phone_book.end()) {
        cout << "There is no records in front" << endl;
        iterator_current_record--;
    } else {
        cout << *iterator_current_record << endl;
    }
}

void PhoneBook::getPrevRecord() {
    iterator_current_record--;

    if (iterator_current_record == list_phone_book.begin()) {
        cout << "There is no back records" << endl;
        iterator_current_record++;
    } else {
        cout << *iterator_current_record << endl;
    }
}

void PhoneBook::insertRecord(Record &record, string &position) {
    if (position == NEXT) {
        list_phone_book.insert(++iterator_current_record, record);
        --iterator_current_record;
    } else {
        list_phone_book.insert(iterator_current_record--, record);
        ++iterator_current_record;
    }
}

void PhoneBook::replaceCurrentRecord(Record &record) {
    *iterator_current_record = record;
}

void PhoneBook::insertRecordInBack(Record &record) {
    list_phone_book.push_back(record);
    iterator_current_record = --list_phone_book.end();
}

void PhoneBook::goForwardOrBack(int n, string &type) {
    if (type == FORWARD) {
        advance(iterator_current_record,n);
    } else {
        advance(iterator_current_record,(-1) * n);
    }

}