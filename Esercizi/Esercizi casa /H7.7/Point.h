#ifndef POINT
#define POINT
#include <iostream>
using namespace std;

class Point {
private:
    int Xc;
    int Yc;
public:
    Point();
    Point(int Xc, int Yc);
    int getXc();
    void setXc(int Xc);
    int getYc();
    void setYc(int Yc);
    friend void  operator <<(ostream& out, const Point& point);
    friend int operator==(const Point& point1, const Point& point2);

};


#endif //PROGRAMMAZIONE_II_POINT_H
