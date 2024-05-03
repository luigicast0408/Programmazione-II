#ifndef RECTANGLE
#define RECTANGLE
#include <iostream>
#include "string"
using namespace std;

class Rectangle{
private:
    float height;
    float width;
public:
    Rectangle();
    Rectangle(double height, double width);
    double getHeight();
    void setHeight(double height);
    double getWidth();
    void setWidth(double width);
    double getArea() const;
    bool isASquare();
    void print();
    friend bool operator <(const Rectangle& rectangle1, const Rectangle& rectangle2);
};


#endif
