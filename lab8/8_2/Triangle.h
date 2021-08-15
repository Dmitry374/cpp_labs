#ifndef OOP_SEM4_TRIANGLE_H
#define OOP_SEM4_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
    using Shape::Shape;
    void Draw() const override;
};


#endif //OOP_SEM4_TRIANGLE_H
