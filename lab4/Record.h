//
// Created by dima on 13.03.2020.
//

#ifndef OOP_SEM4_RECORD_H
#define OOP_SEM4_RECORD_H

#include <iostream>
#include <string>

using namespace std;


class Record {

public:

    Record(string name, string phone);
    ~Record();

    string getName();
    void setName(basic_string<char>);

    string getPhone();
    void setPhone(basic_string<char>);

    Record& operator=(Record&);
    friend ostream& operator<< (ostream&, Record&);


private:
    basic_string<char> name;
    basic_string<char> phone;

};


#endif //OOP_SEM4_RECORD_H
