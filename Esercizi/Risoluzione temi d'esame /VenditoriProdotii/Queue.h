#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue();
    Queue(Node *head, Node *tail);
    void enqueue(Product data);
    void dequeue();
    void printInformation();
};
#endif // QUEUE_H
