#include <iostream>
using namespace std;

template <typename T>
class Data {
private:
    T data;
public:
    Data() {}
    Data(T data) : data(data) {}
    T getData() { return data; }
    void setData(T data) { this->data = data; }
};

template <typename T>
class Node {
private:
    Data<T> data;
    Node<T>* next;
public:
    Node(Data<T> data, Node<T>* next) : data(data), next(next) {}
    Data<T> getData() { return data; }
    Node<T>* getNextNode() { return next; }
    void setNextNode(Node<T>* next) { this->next = next; }
};

template <typename T>
class Stack {
private:
    Node<T>* head;
public:
    Stack(Node<T>* head) : head(head) {}
    Node<T>* getHead() { return head; }
    void setHead(Node<T>* head) { this->head = head; }
    void printStack();
    void push(Data<T> data);
    void pop();
    bool isEmpty() { return head == nullptr; }
    bool searchNode(Data<T> data);
};

template <typename T>
void Stack<T>::printStack() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << "Node->" << current->getData().getData() << endl;
        current = current->getNextNode();
    }
}

template <typename T>
void Stack<T>::push(Data<T> data) {
    Node<T>* newNode = new Node<T>(data, head);
    head = newNode;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        cout << "The list is empty" << endl;
    } else {
        Node<T>* temp = head;
        head = head->getNextNode();
        delete temp;
    }
}

template <typename T>
bool Stack<T>::searchNode(Data<T> data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->getData().getData() == data.getData()) {
            return true;
        }
        current = current->getNextNode();
    }
    return false;
}

int main() {
    // Create an empty stack
    Stack<int> myStack(nullptr);

    // Push some data onto the stack
    myStack.push(Data<int>(5));
    myStack.push(Data<int>(10));
    myStack.push(Data<int>(15));

    // Print the stack
    cout << "Stack contents:" << endl;
    myStack.printStack();

    // Pop an element from the stack
    myStack.pop();

    // Print the updated stack
    cout << "Stack after popping:" << endl;
    myStack.printStack();

    // Search for an element in the stack
    if (myStack.searchNode(Data<int>(5))) {
        cout << "5 found in the stack." << endl;
    } else {
        cout << "5 not found in the stack." << endl;
    }

    if (myStack.searchNode(Data<int>(20))) {
        cout << "20 found in the stack." << endl;
    } else {
        cout << "20 not found in the stack." << endl;
    }

    return 0;
}
