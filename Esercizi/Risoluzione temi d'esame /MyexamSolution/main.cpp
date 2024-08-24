#include <iostream>
#include <string>
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
    void enqueueNodePriority(T data);
    void dequeueNode();
    void printQueue();
};

class Patient {
private:
    int idPatient;
    string name;
    string surname;
    int age;
    bool condition;
public:
    int getIdPatient() { return idPatient; }
    void setIdPatient(int id) { this->idPatient = id; }
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    string getSurname() { return surname; }
    void setSurname(string surname) { this->surname = surname; }
    int getAge() { return age; }
    void setAge(int age) { this->age = age; }
    bool getCondition() { return condition; }
    void setCondition(bool condition) { this->condition = condition; }
    void printPatient() const;
    Patient() : idPatient(0), name(" "), surname(" "), age(0), condition(false) {}
    Patient(int idPatient, string name, string surname, int age, bool condition)
            : idPatient(idPatient), name(name), surname(surname), age(age), condition(condition) {}
};

void Patient::printPatient() const {
    cout << "____PATIENT____" << endl;
    cout << "ID: " << idPatient << endl;
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "Condition: " << (condition ? "GREEN" : "RED") << endl;
    cout << "____PATIENT____" << endl;
}

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
void Queue<T>::enqueueNodePriority(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        int steps = 3;

        while (curr != nullptr && steps > 0 && !curr->getData().getCondition()) {
            prev = curr;
            curr = curr->getNext();
            steps--;
        }

        if (prev == nullptr) { //il nodo va inserito all'inzio della coda
            newNode->setNext(head);
            head = newNode;
        } else { // inserisce il nodo tra prev e curr
            newNode->setNext(prev->getNext());
            prev->setNext(newNode);
        }

        if (newNode->getNext() == nullptr) { //Se il nuovo nodo è stato inserito alla fine della coda, aggiorna tail per puntare al nuovo nodo.
            tail = newNode;
        }
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
void Queue<T>::printQueue() {
    Node<Patient>* current = head;
    while (current != nullptr) {
        current->getData().printPatient();
        current = current->getNext();
    }
}

int main() {
    Queue<Patient> patientQueue;
    Patient patient1 = Patient(1, "A", "B", 10, true);
    Patient patient2 = Patient(2, "C", "D", 20, false);
    Patient patient3 = Patient(3, "E", "F", 30, true);
    Patient patient4 = Patient(4, "G", "H", 40, false);

    patientQueue.enqueueNodePriority(patient1);
    patientQueue.enqueueNodePriority(patient2);
    patientQueue.enqueueNodePriority(patient3);
    patientQueue.enqueueNodePriority(patient4);

    cout << "Patient Queue:" << endl;
    patientQueue.printQueue();

    return 0;
}
