#include "Triangle.h"

Triangle::Triangle(double base, double height) {
    base=1;
    height=1;
}

Triangle::Triangle(double base, double height, std::string colour) {
    this->base=base;
    this->height=height;
    this->colorShape=colour;
}

double Triangle::geBase() { return base;}
void Triangle::setBase(double base) {this->base=base;}

double Triangle::getHeight() {return height;}
void Triangle::setHeight(double height) {this->height=height;}

double Triangle::getArea() {return ((base*height)/2);}

void Triangle::print() {
    cout<<"______Triangle_______"<<endl;
    cout<<"Base: "<<base<<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Colour: "<<colorShape<<endl;
    cout<<"______Triangle_______"<<endl;
}