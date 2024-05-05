#include "Point.h"

Point::Point() {
    Xc=0;
    Yc=0;
}

Point::Point(int Xc, int Yc) {
    this->Xc=Xc;
    this->Yc=Yc;
}

int Point::getXc() {return Xc;}

void Point::setXc(int Xc) {this->Xc=Xc;}

int Point::getYc() {return Yc;}

void Point::setYc(int Yc) {this->Yc=Yc;}

void  operator <<(ostream& out, const Point& point){
    out<<"____POINT______"<<endl;
    out << "(" << point.Xc << ", " << point.Yc << ")";
    out<<"____POINT______"<<endl;
}

int operator==(const Point& point1, const Point& point2){
    return point1.Xc==point2.Xc && point1.Yc==point2.Yc ? 0 : -1;
}
