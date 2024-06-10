#include "BST.h"
#include "Node.h"
#include <iostream>
#include "BST.cpp"
using namespace std;

int main() {
    BST<int> t;
    t.insertNode(8);
    t.insertNode(5);
    t.insertNode(10);
    t.insertNode(2);
    t.insertNode(23);
    t.insertNode(7);
    t.insertNode(6);
    t.insertNode(12);


    cout << t << endl;

    t.deleteNode(10);

    cout << t;
    t.preOrder();

}