#include "Queue.h"
#include <iostream>

template<typename T>
Node<T>::Node(T* data) : data(data), next(nullptr) {}

template<typename T>
T* Node<T>::getData() const { return data; }

template<typename T>
Node<T>* Node<T>::getNext() const { return next; }

template<typename T>
void Node<T>::setNext(Node<T>* next) { this->next = next; }

template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

template<typename T>
void Queue<T>::enqueue(T* data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template<typename T>
void Queue<T>::dequeue() {
    if (!head) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
}

template<typename T>
void Queue<T>::printInformation() {
    Node<T>* current = head;
    while (current) {
        current->getData()->printInformation();
        current = current->getNext();
    }
}
