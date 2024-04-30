#include <iostream>
#include <string>

using namespace std;

class Shape{
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

Shape::Shape() {
    colorShape = "DEFAULT_COLOR";
}

Shape::~Shape() {}

void Shape::print() {
    cout << "Color: " << colorShape << endl;
}

double Shape::getArea() {
    return 0.0; // Or some default value, as it's pure virtual
}


class Rectangle: public Shape{
private:
    float height;
    float width;
public:
    Rectangle();
    Rectangle(double height, double width, string color);
    double getHeight();
    void setHeight(double height);
    double getWidth();
    void setWidth(double width);
    double getArea();
    bool isASquare();
    void print();
    
};

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
    return (height*width);
}

void Rectangle::print() {
    cout<<"__________Rectangle______"<<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Width: "<<width<<endl;
    cout<<"Colour: "<<colorShape<<endl;
    cout<<"__________Rectangle______"<<endl;
}



class Circle : public Shape{
private:
    double radius;
    double Xc;
    double Yc;
public:
    Circle(double radius, double Xc, double Yc);
    Circle(double radius, double Xc, double Yc, string color);

    double getXc();
    void setXc(double Xc);
    double getYc();
    void setYc(double Yc);

    double getRadius(double radius);
    void setRadius(double radius);

    double getCircumference();
    bool isGoniometric();
    double getArea();
    void print();
};

Circle::Circle(double radius, double Xc, double Yc) {
    radius=1;
    Xc=0;
    Yc=0;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

Circle::Circle(double radius, double Xc, double Yc, std::string color) {
    this->Xc=Xc;
    this->Yc=Yc;
    this->radius=radius;
}

double Circle::getXc() {return Xc;}

void Circle::setXc(double Xc) {this->Xc=Xc;}

double Circle::getYc() {return Yc;}


void Circle::setYc(double Yc) {this->Yc=Yc;}

double Circle::getRadius(double radius) {return radius;}


void Circle::setRadius(double radius) {this->radius=radius;}

bool Circle::isGoniometric() {return radius==1 ? true: false;}

double Circle::getCircumference() {return (2*radius)*3.14;}

void Circle::print() {
    cout << "Radius: " << radius << endl;
    cout << "Center: (" << Xc << ", " << Yc << ")" << endl;
    cout << "Color: " << colorShape << endl;
}



class Triangle: public Shape{
private:
    double base;
    double height;
public:
    Triangle(double base, double height);
    Triangle(double base, double height, string  colour);
    double getHeight();
    void setHeight(double height);
    double geBase();
    void setBase(double base);
    double getArea();
    void print();
};

Triangle::Triangle(double base, double height) {
    base=1;
    height=1;
}

Triangle::Triangle(double base, double height, std::string colour) {
    this->base=base;
    this->height=height;
    this->colorShape=colour;
}

double Triangle::geBase() { return base;}
void Triangle::setBase(double base) {this->base=base;}

double Triangle::getHeight() {return height;}
void Triangle::setHeight(double height) {this->height=height;}

double Triangle::getArea() {return ((base*height)/2);}

void Triangle::print() {
    cout<<"______Triangle_______"<<endl;
    cout<<"Base: "<<base<<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Colour: "<<colorShape<<endl;
    cout<<"______Triangle_______"<<endl;
}




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