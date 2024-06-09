#include <iostream>
#include <string> // Aggiunto per utilizzare std::string
using namespace std;

class ArithmeticOperations {
protected:
    double operatorLeft;
    double operatorRight;
public:
    ArithmeticOperations(double operatorLeft, double operatorRight)
            : operatorLeft(operatorLeft), operatorRight(operatorRight) {}

    double getOpLeft() const { return operatorLeft; }
    void setOpLeft(double left) { this->operatorLeft = left; }
    void setOpRight(double right) { this->operatorRight = right; }
    double getOpRight() const { return operatorRight; }

    // Funzione membro virtuale pura per eseguire il calcolo
    virtual double runCalculation() const = 0;

    // Funzione virtuale per stampare le informazioni
    virtual string printInformation() const {
        return "Left Operand: " + to_string(operatorLeft) + ", Right Operand: " + to_string(operatorRight);
    }
};

class Addition : public ArithmeticOperations {
public:
    Addition(double operationLeft, double operationRight)
            : ArithmeticOperations(operationLeft, operationRight) {}

    double runCalculation() const override {
        return getOpLeft() + getOpRight(); // Accesso tramite getter
    }

    string printInformation() const override {
        return "Addition: " + to_string(getOpLeft()) + " + " + to_string(getOpRight()); // Accesso tramite getter
    }
};

class Subtraction : public ArithmeticOperations {
public:
    Subtraction(double operationLeft, double operationRight)
            : ArithmeticOperations(operationLeft, operationRight) {}

    double runCalculation() const override {
        return getOpLeft() - getOpRight(); // Accesso tramite getter
    }

    string printInformation() const override {
        return "Subtraction: " + to_string(getOpLeft()) + " - " + to_string(getOpRight()); // Accesso tramite getter
    }
};

class Multiplication : public ArithmeticOperations {
public:
    Multiplication(double operationLeft, double operationRight)
            : ArithmeticOperations(operationLeft, operationRight) {}

    double runCalculation() const override {
        return getOpLeft() * getOpRight(); // Accesso tramite getter
    }

    string printInformation() const override {
        return "Multiplication: " + to_string(getOpLeft()) + " * " + to_string(getOpRight()); // Accesso tramite getter
    }
};

class Division : public ArithmeticOperations {
public:
    Division(double operationLeft, double operationRight)
            : ArithmeticOperations(operationLeft, operationRight) {}

    double runCalculation() const override {
        if (getOpRight() != 0) {
            return getOpLeft() / getOpRight(); // Accesso tramite getter
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0.0; // Returning 0 in case of division by zero
        }
    }

    string printInformation() const override {
        return "Division: " + to_string(getOpLeft()) + " / " + to_string(getOpRight()); // Accesso tramite getter
    }
};

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node(T data = T(), Node<T>* next = nullptr) : data(data), next(next) {}

    T getData() const { return data; }
    void setData(T data) { this->data = data; }
    Node<T>* getNext() const { return next; }
    void setNext(Node<T>* next) { this->next = next; }
};

template <typename T>
class Stack{
public:
    Node<T>* head;
    Stack() : head(nullptr) {} // Costruttore di default
    void push(T data);
    void pop();
    void printStack();
    bool isEmpty() const { return head == nullptr; } // Metodo const
};

template <typename T>
void Stack<T>::printStack() {
    Node<T>* current = head;
    while (current != nullptr){
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node<T>* temp = head;
    head = head->getNext(); // Aggiorniamo la testa al prossimo nodo
    delete temp; // Deallochiamo il nodo rimosso
}

template <typename T>
class Queue{
public:
    Node<T>* head; // Modificato in puntatore
    Node<T>* tail; // Modificato in puntatore
    Queue() : head(nullptr), tail(nullptr) {} // Costruttore di default
    Queue(Node<T>* head, Node<T>* tail) : head(head), tail(tail) {} // Costruttore con parametri
    void printQueue();
    void deQueue();
    void enQueue(T value);
    bool isEmpty() const { return head == nullptr; } // Metodo const
};

template <typename T>
void Queue<T>::printQueue() {
    Node<T>* current = head;
    while (current != nullptr){
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

template <typename T>
void Queue<T>::enQueue(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode); // Modificato da tail.setNode(newNode);
        tail = newNode;
    }
}

int main() {
    Addition add(5.0, 3.0);
    Subtraction sub(10.0, 4.0);
    Multiplication mul(6.0, 2.0);
    Division div(9.0, 3.0);

    // Esecuzione delle operazioni e stampa dei risultati
    cout << "Addition result: " << add.runCalculation() << endl;
    cout << "Subtraction result: " << sub.runCalculation() << endl;
    cout << "Multiplication result: " << mul.runCalculation() << endl;
    cout << "Division result: " << div.runCalculation() << endl;

    // Creazione di una Pila di double
    Stack<double> doubleStack;
    doubleStack.push(10.5);
    doubleStack.push(20.3);
    doubleStack.push(30.7);

    // Stampa della Pila di double
    cout << "\nDouble stack:" << endl;
    doubleStack.printStack();

    // Creazione di una Coda di int
    Queue<int> intQueue;
    intQueue.enQueue(10);
    intQueue.enQueue(20);
    intQueue.enQueue(30);

    // Stampa della Coda di int
    cout << "\nInteger queue:" << endl;
    intQueue.printQueue();

    return 0;
}
