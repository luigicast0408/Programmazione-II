#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Product.h"
using namespace std;

class Node {
private:
    Product data;
    Node* next;
public:
    Node(Product data);
    Product getData() const;
    Node* getNext() const;
    void setNext(Node* next);
};

#endif // NODE_H
