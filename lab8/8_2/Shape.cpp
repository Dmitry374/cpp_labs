#include "Shape.h"

string Shape::getName() {
    return name;
}

void Shape::setName(string &sName) {
    name = sName;
}

int Shape::getX() {
    return x;
}

void Shape::setX(int &coordX) {
    x = coordX;
}

int Shape::getY() {
    return y;
}

void Shape::setY(int &coordY) {
    y = coordY;
}

bool Shape::IsMoreLeft(const Shape *shape) const {
    return x < shape->x;
}

bool Shape::IsUpper(const Shape *shape) const {
    return y > shape->y;
}

ostream& operator<<(ostream& out, Shape &shape) {
    out << shape.name << " " << "(" << shape.x << ", " << shape.y << ")" << endl;

    return out;
}