//
// Created by dima on 13.03.2020.
//

#ifndef OOP_SEM4_PHONEBOOK_H
#define OOP_SEM4_PHONEBOOK_H

#include <iostream>
#include <string>
#include <list>
#include "Record.h"

using namespace std;

typedef list<Record> list_type;

class PhoneBook {

public:
    list_type list_phone_book;

    string NEXT = "next";
    string PREV = "prev";

    string FORWARD = "forward";
    string BACK = "back";

    PhoneBook();

    ~PhoneBook();

    void printPhoneBook();

    void resetMyIterator();

    void setPhoneRecord(Record&);

    void getCurrentRecord();

    Record& returnCurrentRecord();

    void getNextRecord();

    void getPrevRecord();

    void insertRecord(Record&, string&);

    void replaceCurrentRecord(Record&);

    void insertRecordInBack(Record&);

    void goForwardOrBack(int, string&);

private:
    list_type::iterator iterator_current_record;

};


#endif //OOP_SEM4_PHONEBOOK_H
