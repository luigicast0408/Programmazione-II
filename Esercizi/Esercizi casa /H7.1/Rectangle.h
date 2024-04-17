//
// Created by Luigi Domenico Castano on 17/04/24.
//

#ifndef RECTANGLE
#define RECTANGLE


class Rectangle {
private:
    int base;
    int height;

public:
    Rectangle();
    Rectangle(int base, int height);

    int getBase();
    void setBase(int base);
    int getHeight();
    void setHeight(int height);
    float calculationArea();
    float calculationArea(int side);
    float calculationPerimeter();
    float calculationPerimeter(int side);
    float calculationDiagonal();
    bool checkSquare() const;
};


#endif
