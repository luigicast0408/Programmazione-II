#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
    T getData() { return data; }
    void setData(T data) { this->data = data; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T>* next) { this->next = next; }
};

template <typename T>
class Queue {
public:
    Node<T>* head, *tail;
    Queue() : head(nullptr), tail(nullptr) {}
    bool isEmpty() { return tail == nullptr || head == nullptr; }
    void enqueueNode(T data);
    void dequeueNode();
    void printQueue();
    bool searchNode(T data);
};

template <typename T>
void Queue<T>::enqueueNode(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <typename T>
void Queue<T>::dequeueNode() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

template <typename T>
bool Queue<T>::searchNode(T data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->getData() == data) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

template <typename T>
void Queue<T>::printQueue() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << "NODE->" << current->getData() << endl;
        current = current->getNext();
    }
}

int main() {
    Queue<int> queue;
    queue.enqueueNode(10);
    queue.enqueueNode(20);
    queue.enqueueNode(30);

    cout << "Queue after enqueuing 10, 20, 30:" << endl;
    queue.printQueue();

    queue.dequeueNode();
    cout << "Queue after dequeuing one element:" << endl;
    queue.printQueue();

    bool found = queue.searchNode(20);
    cout << "Searching for 20 in the queue: " << (found ? "Found" : "Not Found") << endl;

    found = queue.searchNode(40);
    cout << "Searching for 40 in the queue: " << (found ? "Found" : "Not Found") << endl;

    return 0;
}
