#include "Circle.h"

Circle::Circle(double radius, double Xc, double Yc) {
    radius=1;
    Xc=0;
    Yc=0;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

Circle::Circle(double radius, double Xc, double Yc, std::string color) {
    this->Xc=Xc;
    this->Yc=Yc;
    this->radius=radius;
}

double Circle::getXc() {return Xc;}

void Circle::setXc(double Xc) {this->Xc=Xc;}

double Circle::getYc() {return Yc;}


void Circle::setYc(double Yc) {this->Yc=Yc;}

double Circle::getRadius(double radius) {return radius;}


void Circle::setRadius(double radius) {this->radius=radius;}

bool Circle::isGoniometric() {return radius==1 ? true: false;}

double Circle::getCircumference() {return (2*radius)*3.14;}

void Circle::print() {
    cout << "Radius: " << radius << endl;
    cout << "Center: (" << Xc << ", " << Yc << ")" << endl;
    cout << "Color: " << colorShape << endl;
}