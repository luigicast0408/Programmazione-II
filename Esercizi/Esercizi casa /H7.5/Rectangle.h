#ifndef RECTANGLE
#define RECTANGLE
#include <iostream>
#include "string"
#include "Shape.h"
using namespace std;

class Rectangle: public Shape{
private:
    float height;
    float width;
public:
    Rectangle();
    Rectangle(double height, double width, string color);
    double getHeight();
    void setHeight(double height);
    double getWidth();
    void setWidth(double width);
    double getArea();
    bool isASquare();
    void print();
};


#endif
