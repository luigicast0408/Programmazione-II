#include "Shape.h"

Shape::Shape() {
    colorShape = "DEFAULT_COLOR";
}

Shape::~Shape() {}

void Shape::print() {
    cout << "Color: " << colorShape << endl;
}

double Shape::getArea() {
    return 0.0;
}
