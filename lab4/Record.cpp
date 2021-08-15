//
// Created by dima on 13.03.2020.
//

#include "Record.h"

Record::Record(string name, string phone) {
    setName(name);
    setPhone(phone);
}

Record::~Record() {
    delete &name;
    delete &phone;
}

string Record::getName() {
    return name;
}

void Record::setName(basic_string<char> sName) {
    name = sName;
}

string Record::getPhone() {
    return phone;
}

void Record::setPhone(basic_string<char> sPhone) {
    phone = sPhone;
}

Record& Record::operator=(Record& record) {
    setName(record.getName());
    setPhone(record.getPhone());

    return *this;
}

ostream& operator<<(ostream& out, Record &record) {
    out << record.getName() << ":\t " << record.getPhone() << endl;

    return out;
}