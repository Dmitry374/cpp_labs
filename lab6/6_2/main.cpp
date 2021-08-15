/*    2. Написать программу, которая выполняет следующие действия (все операции должны выполняться с помощью стандартных алгоритмов):
        a. Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником, квадратом, прямоугольником или пяти угольником. Структура описывающая геометрическую фигуру  определена ниже,
        b. Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
        c. Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
        d. Удаляет все пятиугольники
        e. На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент этого вектора содержит координаты одной из вершину первой фигуры, второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
        f. Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
        g. Распечатывает вектор после каждого этапа работы


Геометрическая фигура задается следующей структурой:
typedef  struct
{
    int vertex_num;      // количество вершин, для треугольника 3, для квадрата и
                                   // прямоугольника 4, для пяти угольника 5
    vector<Point> vertexes;   // вектор содержащий координаты вершин фигуры
    // Для треугольника содержит 3 элемента
 				    // Для квадрата и прямоугольника содержит 4
                                             // элемента
                                             // Для пятиугольника 5 элементов
} Shape;

typedef struct
{
    int x,y;
} Point; */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>

#define SIZE 5

using namespace std;
using namespace std::placeholders;

static const string TRIANGLE = "Треугольник";
static const string RECTANGLE = "Прямоугольник";
static const string SQUARE = "Квадрат";
static const string PENTAGON = "Пятиугольник";

struct Point {
    int x, y;

    string toString() {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    friend ostream &operator<<(ostream &out, const Point &point) {
        out << "(" << point.x << ", " << point.y << ")" << endl;
        return out;
    }


};

struct Shape {
    string name;
    int vertex_num;      // количество вершин, для треугольника 3, для квадрата и
    // прямоугольника 4, для пяти угольника 5
    vector<Point> vertexes;   // вектор содержащий координаты вершин фигуры
    // Для треугольника содержит 3 элемента
    // Для квадрата и прямоугольника содержит 4
    // элемента
    // Для пятиугольника 5 элементов

    int isSquare; // 0 - квадрат, 1 - прямоугольник

    friend ostream &operator<<(ostream &out, const Shape &shape) {

        out << shape.name << " (" << shape.vertex_num << ")" << endl;

        vector<Point> vectorPoints = shape.vertexes;

        string coordinates;

        for (auto point : vectorPoints) {
            coordinates = coordinates + point.toString() + " ";
        }

        out << coordinates << endl;

//        for (auto vectorPoint : vectorPoints) {
//            out << vectorPoint;
//        }

        return out;
    }

};

vector<Shape> shapes;
vector<Point> points;

void fillShapesVector();

void printShapesVector();

void printPointsVector();

void print_elem(Shape &shape);

// Подсчитывает общее количество вершин всех фигур содержащихся в векторе
void countVertexSum();

// Подсчет количества каждой фигуры
void countKolFigureTypes();

// Удаляем определенную фигуру из списка
void removeFigure(const string &);

// Создает vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры
void createPointsVector();

void print_point_elem(Point &point);

bool point_equals(const Point &, const Point &);

void sortVectorShapeByFigure();

int main() {

    fillShapesVector();

    cout << "a. Заполняем вектор геометрическими фигурами" << endl;
    printShapesVector();

    cout << endl;

    cout << "b. Общее количество вершин всех фигур:" << endl;
    countVertexSum();

    cout << endl;

    cout << "c. Количество каждой фигуры:" << endl;
    countKolFigureTypes();

    cout << endl;

    string figure = PENTAGON;
    cout << "d. Удаляем фигуру (" << figure << ")" << " из списка:" << endl;
    removeFigure(figure);

    cout << endl;

    cout << "e. Создаем vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры:" << endl;
    createPointsVector();

    cout << "Результат:" << endl;
    printPointsVector();

    cout << endl;

    cout
            << "f. Изменяем вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники:"
            << endl;
    sortVectorShapeByFigure();

    cout << "Результат:" << endl;
    printShapesVector();

}

void fillShapesVector() {
    srand((unsigned) time(0));
    for (int i = 0; i < SIZE; i++) {
        Shape shape;

        int vertex_num = random() % 3 + 3;

        shape.vertex_num = vertex_num;

        shape.isSquare = random() % 2;

        string figure;

        switch (shape.vertex_num) {
            case 3:
                figure = TRIANGLE;
                break;
            case 4:
                if (shape.isSquare) {
                    figure = SQUARE;
                } else {
                    figure = RECTANGLE;
                }
                break;
            case 5:
                figure = PENTAGON;
                break;
        }

        shape.name = figure;


        for (int j = 0; j < vertex_num; j++) {
            Point point;

            point.x = random() % 41 - 20;
            point.y = random() % 41 - 20;

            shape.vertexes.push_back(point);
        }

        shapes.push_back(shape);
    }

}

void printShapesVector() {
    cout << "-----------------------------------------------" << endl;
    for_each(shapes.begin(), shapes.end(), print_elem);
    cout << "-----------------------------------------------" << endl;
}

void print_elem(Shape &shape) {
    cout << shape << endl;
}

void countVertexSum() {
    cout << accumulate(shapes.begin(), shapes.end(), 0, bind(plus<int>(), _1, bind(&Shape::vertex_num, _2))) << endl;
}

void countKolFigureTypes() {

    int triangles_count = count_if(shapes.begin(), shapes.end(),
                                   [&](const Shape &s) {
                                       return s.name == TRIANGLE;
                                   });

    int squares_count = count_if(shapes.begin(), shapes.end(),
                                 [&](const Shape &s) {
                                     return s.name == SQUARE;
                                 });

    int rectangles_count = count_if(shapes.begin(), shapes.end(),
                                    [&](const Shape &s) {
                                        return s.name == RECTANGLE;
                                    });

    int pentagons_count = count_if(shapes.begin(), shapes.end(),
                                   [&](const Shape &s) {
                                       return s.name == PENTAGON;
                                   });

    cout << "Количество треугольников: " << triangles_count << endl;
    cout << "Количество квадратов: " << squares_count << endl;
    cout << "Количество прямоугольников: " << rectangles_count << endl;
    cout << "Количество пятиугольников: " << pentagons_count << endl;
}

void removeFigure(const string &figure) {

    auto find_element = find_if(shapes.begin(), shapes.end(),
                                [&figure](const Shape &shape) {
                                    return shape.name == figure;
                                });

    if (find_element != shapes.end()) {
        auto new_end = remove_if(shapes.begin(), shapes.end(),
                                 [&figure](const Shape &shape) {
                                     return shape.name == figure;
                                 });

        shapes.erase(new_end, shapes.end());

        cout << "Результат:" << endl;
        printShapesVector();

    } else {
        cout << "Элемент '" << figure << "' не был найден в списке !!!" << endl;
    }
}

void createPointsVector() {

    for_each(shapes.begin(), shapes.end(),
             [&](const Shape &shape) {

                 srand((unsigned) time(0));
                 // выбираем рандомно позицию элемента Point из каждого вектора (shape.vertex_num) элемента Shape
                 const int pos = random() % shape.vertex_num;

                 // Рандомный элемент Point (рандомная координата из Shape)
                 const Point random_point = shape.vertexes.at(pos);

                 copy_if(shape.vertexes.begin(), shape.vertexes.end(), back_inserter(points),
                         [&random_point](const Point &point) {
                             return point_equals(random_point, point);
                         }
                 );
             });

}

bool point_equals(const Point &point1, const Point &point2) {
    return point1.x == point2.x && point1.y == point2.y;
}

void printPointsVector() {
    cout << "-----------------------------------------------" << endl;
    for_each(points.begin(), points.end(), print_point_elem);
    cout << "-----------------------------------------------" << endl;
}

void print_point_elem(Point &point) {
    cout << point << endl;
}

void sortVectorShapeByFigure() {
    sort(shapes.begin(), shapes.end(),
         [](const Shape &shape1, const Shape &shape2) -> bool {
             return shape1.vertex_num < shape2.vertex_num ||
                    (shape1.vertex_num == shape2.vertex_num && shape1.isSquare > shape2.isSquare);
         });
}
