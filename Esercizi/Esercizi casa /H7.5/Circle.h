#ifndef CIRCLE
#define CIRCLE
#include <iostream>
#include "string"
#include "Shape.h"

class Circle : public Shape{
private:
    double radius;
    double Xc;
    double Yc;
public:
    Circle(double radius, double Xc, double Yc);
    Circle(double radius, double Xc, double Yc, string color);

    double getXc();
    void setXc(double Xc);
    double getYc();
    void setYc(double Yc);

    double getRadius(double radius);
    void setRadius(double radius);

    double getCircumference();
    bool isGoniometric();
    double getArea();
    void print();
};
#endif
