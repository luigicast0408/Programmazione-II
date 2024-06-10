#include "BST.h"
#include "Classes.h"
using  namespace std;

int main() {
    int sizeRectangle, sizeCircle, sizeTriangle;
    cout<<"insert the number of rectangles"<<endl;
    cin>>sizeRectangle;

    cout<<"insert the number of circles"<<endl;
    cin>>sizeCircle;

    cout<<"insert the number of triangles"<<endl;
    cin>>sizeTriangle;

    BST<Rectangle> BSTRectangle;
    BST<Triangle>  BSTTriangle;
    BST<Circle>  BSTCircle;

    for (int i = 0; i < sizeRectangle; ++i) {
        Rectangle rectangle = Rectangle(i,i+1);
        BSTRectangle.insertNode(rectangle);
    }

    for (int i = 0; i < sizeCircle; i++) {
        Circle circle=Circle((i+2)+10);
        BSTCircle.insertNode(circle);
    }

    for (int i = 0; i < sizeTriangle; ++i) {
        Triangle triangle=Triangle(10*i*9);
        BSTTriangle.insertNode(triangle);
    }
    BST<Shape> remElem;

    cout << BSTRectangle << endl;
    cout << BSTCircle << endl;
    cout << BSTTriangle << endl;
}
