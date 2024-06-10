#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
public:
    Node(T value, Node<T>* left = nullptr, Node<T>* right = nullptr, Node<T>* parent = nullptr): value(value), left(left), right(right), parent(parent) {}
    T getValue(){return value;}
    void setValue(T value) { this->value = value; }
    Node<T>* getNodeLeft() { return left; }
    void setNodeLeft(Node<T>* left) { this->left = left; }
    Node<T>* getNodeRight() { return right; }
    void setNodeRight(Node<T>* right) { this->right = right; }
    Node<T>* getNodeParent() { return parent; }
    void setNodeParent(Node<T>* parent) { this->parent = parent; }
};

#endif
