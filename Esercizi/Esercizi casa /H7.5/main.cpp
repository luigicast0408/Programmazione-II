#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
using namespace std;
int main(){
    Shape* shape[3];
    Rectangle rectangle=Rectangle(10,10,"RED");
    Circle circle= Circle(3,2,2,"RED");
    Triangle triangle=Triangle(3,3,"RED");
    shape[0]=&rectangle;
    shape[1]=&circle;
    shape[2]=&triangle;
    int sum=0;
    for (int i = 0; i <3 ; ++i) {
        shape[i]->print();
        cout<<"Area: "<<shape[i]->getArea()<<endl;
        sum+=shape[i]->getArea();
    }
    cout<<"Average of Area is "<<(sum/3)<<endl;
}
