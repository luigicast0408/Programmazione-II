#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
    T* data;
    Node<T>* next;
public:
    Node(T* data);
    T* getData() const;
    Node<T>* getNext() const;
    void setNext(Node<T>* next);
};

#endif // NODE_H
