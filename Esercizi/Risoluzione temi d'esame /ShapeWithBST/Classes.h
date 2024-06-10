#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    Shape(){}
    virtual ~Shape() {}
    virtual double getArea() = 0;
    virtual string printShape() = 0; // Make this pure virtual
};

class Rectangle : public Shape {
private:
    double base;
    double height;
public:
    Rectangle(double base, double height) : base(base), height(height) {}
    double getBase() { return base; }
    void setBase(double base) { this->base = base; }
    double getHeight() { return height; }
    void setHeight(double height) { this->height = height; }
    double getArea()  { return base * height; }
    string printShape(){
        return "Rectangle: Base = " + to_string(base) + ", Height = " + to_string(height);
    }
    friend bool operator< (Rectangle r1, Rectangle r2){
        return r1.base < r2.base && r1.height < r2.height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double getRadius() { return radius; }
    void setRadius(double radius) { this->radius = radius;}
    double getArea() { return pow(radius, 2) * M_PI;}
    string printShape(){
        return "Circle: Radius = "+ to_string(radius);
    }
    friend  bool  operator < (Circle c1, Circle c2){
        return c1.radius < c2.radius;
    }
};

class Triangle : public Shape{
private:
    double side;
public:
    Triangle(double side) : side(side) {}
    double getSide() { return side; }
    void setSide(double side) { this->side = side; }
    double getArea() { return pow(side, 2);}
    string  printShape(){
        return "Triangle: Side = "+ to_string(side);
    }
    friend  bool  operator < (Triangle t1, Triangle t2){
        return t1.side < t2.side;
    }
};
#endif
