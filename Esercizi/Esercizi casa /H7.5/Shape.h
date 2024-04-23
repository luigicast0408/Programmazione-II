//
// Created by Luigi Domenico Castano on 23/04/24.
//

#ifndef SHAPE
#define SHAPE
#include <iostream>
#include "string"
using namespace std;


class Shape {
    protected:
        string colorShape;
    public:
        Shape();
        Shape(string color);
        virtual ~Shape();
        string getColor();
        void setColor(string color);
        virtual void print();
        virtual double getArea();
};


#endif
