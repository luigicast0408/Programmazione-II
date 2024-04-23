#include "Rectangle.h"
Rectangle::Rectangle() {
    height=1;
    width=1;
    colorShape="RED";
}

Rectangle::Rectangle(double height, double width, std::string color) {
    this->height=height;
    this->width=width;
    this->colorShape=color;
}

double Rectangle::getHeight() { return  height;}

void Rectangle::setHeight(double height) {this->height=height;}

double Rectangle::getWidth() {return width;}

void Rectangle::setWidth(double width) {this->width=width;}

bool Rectangle::isASquare() {return width==height ? true: false;}

double Rectangle::getArea() {
    return (height*width)/2;
}

void Rectangle::print() {
    cout<<"__________Rectangle______"<<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Width: "<<width<<endl;
    cout<<"Colour: "<<colorShape<<endl;
    cout<<"__________Rectangle______"<<endl;
}

