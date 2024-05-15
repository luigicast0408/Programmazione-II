#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template<typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    void enqueue(T* data);
    void dequeue();
    void printInformation();
};

#endif // QUEUE_H
