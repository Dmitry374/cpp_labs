#ifndef OOP_SEM4_CIRCLE_H
#define OOP_SEM4_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    using Shape::Shape;
    void Draw() const override;
};


#endif //OOP_SEM4_CIRCLE_H
