//
// Created by Luigi Domenico Castano on 11/06/24.
//

#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T value;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node(T v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
    T getValue() const { return value; }
    Node* getNodeLeft() const { return left; }
    Node* getNodeRight() const { return right; }
    Node* getNodeParent() const { return parent; }
    void setNodeLeft(Node* l) { left = l; }
    void setNodeRight(Node* r) { right = r; }
    void setNodeParent(Node* p) { parent = p; }
};


#endif //PROGRAMMAZIONE_II_NODE_H
