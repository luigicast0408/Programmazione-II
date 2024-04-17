#include "Rectangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangle::Rectangle() { //constutture di default
    base=0;
    height=0;
}

Rectangle::Rectangle(int base, int height) { // c param
    this->base=base;
    this->height=height;
}
//metodi get e set per far viuslizzari gli attributi privati alle altri classi
//implementazione dei vari metodi che si ri riferisco alla classe Rettangolo (Rettangolo::)


int Rectangle::getBase() {
    return base;
}

void Rectangle::setBase(int base) {
    this->base=base;
}


float Rectangle::calculationArea() {
    return base*height;
}

float Rectangle::calculationPerimeter() {
    return ((base*2)+(height*2));
}


float Rectangle::calculationDiagonal() {
    return (sqrt(pow(base,2)+ pow(height,2)));
}

float Rectangle::calculationPerimeter(int side) {
    return side*4;
}

float Rectangle::calculationArea(int side) {
    return pow(side,2);
}

bool Rectangle::checkSquare()  const{
    return base==height ? true: false;
}