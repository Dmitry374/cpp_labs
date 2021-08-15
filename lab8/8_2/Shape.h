#ifndef OOP_SEM4_SHAPE_H
#define OOP_SEM4_SHAPE_H

#include "Shape.h"

#include <iostream>

using namespace std;

class Shape {

protected:
    int x, y;
    string name;

public:

    Shape(string name, int x, int y) : name(name), x(x), y(y) {};
    ~Shape() = default;

    string getName();
    void setName(string&);

    int getX();
    void setX(int&);

    int getY();
    void setY(int&);

    bool IsMoreLeft(const Shape *) const;

    bool IsUpper(const Shape *) const;

    virtual void Draw() const = 0;


    friend ostream& operator<< (ostream&, Shape&);

};


#endif //OOP_SEM4_SHAPE_H
