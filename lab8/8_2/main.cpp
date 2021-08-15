/*    2. Разработать программу, которая:
        a. Реализует иерархию геометрических фигур состоящую из:
            i. Класс Shape.
                1. Содержит информацию о положении центра фигуры (координаты x и y).

                2. Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее
                (определяется по положению центра) чем фигура переданная в качестве аргумента

                3. Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше
                (определяется по положению центра) чем фигура переданная в качестве аргумента

                4. Определяет чисто виртаульную функцию рисования Draw (каждая фигура в реализации этой функци
                должна выводить на стандартный вывод свое название и положение цента)

            ii. Класс Circle производный от класса Shape
                1. Реализует Draw
            iii. Класс Triangle производный от класса Shape
                1. Реализует Draw
            iv. Класс Square производный от класса Shape
                1. Реализует Draw

        b. Содержит список list<Shape*>, заполенный указателями на различные фигуры

        c. С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры

        d. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева-направо
        (имется в виду, что в начале списка должны идти фигуры находящиеся левее, координата x ) и выводит фигуры (Draw)

        e. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа-налево и выводит фигуры

        f. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху-вниз и выводит фигуры

        g. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу-вверх и выводит фигуры
        */

#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <functional>

#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

#define SIZE 10

using namespace std;

void fillShapesList(list<Shape*> &);

Shape *getShapeItem();

void printShapesList(list<Shape*> &);

void sortLeftToRight(list<Shape*> &);

void sortRightToLeft(list<Shape*> &);

void sortUpperToDown(list<Shape*> &);

void sortDownToUpper(list<Shape*> &);

int main() {

    list<Shape*> shapes;

    fillShapesList(shapes);

    cout << "c. Список всех фигур:" << endl;
    printShapesList(shapes);

    cout << "d. Сортировка слева-направо" << endl;
    sortLeftToRight(shapes);

    cout << "e. Сортировка справа-налево" << endl;
    sortRightToLeft(shapes);

    cout << "f. Сортировка сверху-вниз" << endl;
    sortUpperToDown(shapes);

    cout << "f. Сортировка снизу-вверх" << endl;
    sortDownToUpper(shapes);

}

void fillShapesList(list<Shape *> &shapes) {
    srand((unsigned) time(0));
    for (int i = 0; i < SIZE; i++) {
        shapes.push_back(getShapeItem());
    }
}

Shape *getShapeItem() {

    int type = random()%3;
    Shape *shape;

    int x = random()%40 - 20;
    int y = random()%40 - 20;

    switch (type) {
        case 0:
            shape = new Circle("Круг", x, y);
            break;
        case 1:
            shape = new Triangle("Треугольник", x, y);
            break;
        case 2:
            shape = new Square("Квадрат", x, y);
            break;
        default:
            shape = new Circle("Круг", x, y);
            break;
    }

    return shape;
}

void printShapesList(list<Shape *> &shapes) {
    for_each(shapes.begin(), shapes.end(), mem_fun(&Shape::Draw));
    cout << endl;
}

void sortLeftToRight(list<Shape *> &shapes) {
    shapes.sort(mem_fn(&Shape::IsMoreLeft));
    printShapesList(shapes);
}

void sortRightToLeft(list<Shape *> &shapes) {
    shapes.sort(not2(mem_fn(&Shape::IsMoreLeft)));
    printShapesList(shapes);
}

void sortUpperToDown(list<Shape *> &shapes) {
    shapes.sort(mem_fn(&Shape::IsUpper));
    printShapesList(shapes);
}

void sortDownToUpper(list<Shape *> &shapes) {
    shapes.sort(not2(mem_fn(&Shape::IsUpper)));
    printShapesList(shapes);
}



