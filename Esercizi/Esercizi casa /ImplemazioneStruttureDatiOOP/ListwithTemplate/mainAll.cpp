#include <iostream>
using namespace std;

template <typename T>
class Data {
private:
    T value;
public:
    Data(T value);
    T getValue();
    void setValue(T value);
};

template <typename T>
Data<T>::Data(T value) {
    this->value=value;
}

template <typename T>
T Data<T>::getValue() {
    return value;
}

template <typename T>
void  Data<T>::setValue(T value) {
    this->value=value;
}

template <typename T>
class Node {
public:
    Data<T> data;
    Node<T> *next;
    Node(Data<T> data, Node<T>*next);
};

template <typename T>
Node<T>::Node(Data<T> data, Node<T>* next) : data(data), next(next) {}

template <typename T>
class List {
public:
    Node<T> *head;
    List(Node<T> *head);
    void insertNode(Data<T> data);
    void deleteNode(Data<T> data);
    bool isEmpty();
    bool searchNode(Data<T> data);
    void printList();
};

template<typename T>
List<T>::List(Node<T> *head) {
    this->head=head;
}

template<typename T>
bool List<T>::isEmpty() {
    return head == nullptr;
}


template<typename T>
bool List<T>::searchNode(Data<T> data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data.getValue() == data.getValue()) {
            return true;
        }
        current = current->next;
    }
    return false;
}


template<typename T>
void List<T>::printList() {
    cout << "_______LIST_______" << endl;
    Node<T>* currentNode = head;
    while (currentNode != nullptr) {
        cout << "List-> " << currentNode->data.getValue() << endl;
        currentNode = currentNode->next; // Avanzamento al nodo successivo
    }
    cout << "_______LIST_______" << endl;
}


template<typename T>
void List<T>::insertNode(Data<T> data) {
    Node<T>* newNode = new Node<T>(data, nullptr);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr && current->data.getValue() < data.getValue()) {
            prev = current;
            current = current->next;
        }
        if (prev != nullptr)
            prev->next = newNode;
        else
            head = newNode; // Inserimento in testa
        newNode->next = current; // Aggiornamento del collegamento next
    }
}


template<typename T>
void List<T>::deleteNode(Data<T> data) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;
    while (current != nullptr && current->data.getValue() != data.getValue()) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) { // Elemento esiste nella lista
        if (prev != nullptr) // Non è la testa della lista
            prev->next = current->next;
        else
            head = current->next; // Aggiornamento del puntatore al primo elemento
        delete current;
    }
}


int main() {
    Node<int>* head = nullptr;
    List<int> list = List<int>(head);

    Data<int> data = Data<int>(2);
    list.insertNode(data);

    // Controllo se il nodo è stato inserito correttamente
    if (list.searchNode(data)) {
        cout << "Node inserted successfully." << endl;
    } else {
        cout << "Failed to insert node." << endl;
    }

    list.printList();

    // Elimina il nodo
    list.deleteNode(data);

    // Controlla se il nodo è stato eliminato correttamente
    if (!list.searchNode(data)) {
        cout << "Node deleted successfully." << endl;
    } else {
        cout << "Failed to delete node." << endl;
    }

    list.printList();

    return 0;
}
