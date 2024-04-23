#ifndef PROGRAMMAZIONE_II_TRIANGLE_H
#define PROGRAMMAZIONE_II_TRIANGLE_H

#include <iostream>
#include "string"
#include "Shape.h"

class Triangle: public Shape{
private:
    double base;
    double height;
public:
    Triangle(double base, double height);
    Triangle(double base, double height, string  colour);
    double getHeight();
    void setHeight(double height);
    double geBase();
    void setBase(double base);
    double getArea();
    void print();
};


#endif //PROGRAMMAZIONE_II_TRIANGLE_H
