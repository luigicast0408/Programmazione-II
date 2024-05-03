#include "Rectangle.h"

Rectangle::Rectangle() {
    height=0;
    width=0;
}

Rectangle::Rectangle(double height, double width) {
    this->height=height;
    this->width=width;
}

double Rectangle::getHeight() { return  height;}

void Rectangle::setHeight(double height) {this->height=height;}

double Rectangle::getWidth() {return width;}

void Rectangle::setWidth(double width) {this->width=width;}

bool Rectangle::isASquare() {return width==height ? true: false;}

double Rectangle::getArea() const {return (height*width);}

void Rectangle::print() {
    cout<<"__________Rectangle______"<<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Width: "<<width<<endl;
    cout<<"__________Rectangle______"<<endl;
}

bool operator <(const Rectangle& rectangle1, const Rectangle& rectangle2) {
    return rectangle1.getArea()<rectangle2.getArea() ? true : false;
}