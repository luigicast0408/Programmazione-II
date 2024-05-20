#include "Queue.h"
#include <iostream>

Queue::Queue(): head(nullptr), tail(nullptr) {}
Queue::Queue(Node *head, Node *tail) : head(head), tail(tail)  {}

void Queue::enqueue(Product data) {
    Node * newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

void Queue::dequeue() {
    if (!head) {
        cout << "Queue is empty!" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->getNext();
    delete temp;
}

void Queue::printInformation() {
    Node* current = head;
    while (current) {
        current->getData().printInformation();
        current = current->getNext();
    }
}
