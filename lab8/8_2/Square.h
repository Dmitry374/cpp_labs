#ifndef OOP_SEM4_SQUARE_H
#define OOP_SEM4_SQUARE_H

#include "Shape.h"

class Square : public Shape {
    using Shape::Shape;
    void Draw() const override;
};


#endif //OOP_SEM4_SQUARE_H
