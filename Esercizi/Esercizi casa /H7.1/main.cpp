#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {

    Rectangle rectangle = Rectangle(2, 2);
    Rectangle rectangle1 = Rectangle(6, 2);

    cout << "Si ha un quadrato di Area: " << rectangle.calculationPerimeter(rectangle.getBase())
         << "Perimetro: " << rectangle.calculationPerimeter(rectangle.getBase())<<endl;
    cout << "Si ha un rettangolo di Area: " << rectangle1.calculationPerimeter()
         << "Perimetro: " << rectangle1.calculationPerimeter()<<endl;

    return 0;
}