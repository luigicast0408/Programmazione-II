#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next);
};

template <typename T>
Node<T>::Node(T data, Node<T>* next) : data(data), next(next) {}

template <typename T>
class List {
public:
    Node<T>* head;
    List(Node<T>* head);
    void insertNode(T data);
    void deleteNode(T data);
    bool isEmpty();
    bool searchNode(T data);
    void printList();
};

template<typename T>
List<T>::List(Node<T>* head) {
    this->head = head;
}

template<typename T>
bool List<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
bool List<T>::searchNode(T data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
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
        cout << "List-> " << currentNode->data << endl;
        currentNode = currentNode->next;
    }
    cout << "_______LIST_______" << endl;
}

template<typename T>
void List<T>::insertNode(T data) {
    Node<T>* newNode = new Node<T>(data, nullptr);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr && current->data < data) {
            prev = current;
            current = current->next;
        }
        if (prev != nullptr)
            prev->next = newNode;
        else
            head = newNode;
        newNode->next = current;
    }
}

template<typename T>
void List<T>::deleteNode(T data) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;
    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) {
        if (prev != nullptr)
            prev->next = current->next;
        else
            head = current->next;
        delete current;
    }
}

int main() {
    Node<int>* head = nullptr;
    List<int> list = List<int>(head);

    int data = 2;
    list.insertNode(2);
    list.insertNode(4);
    list.insertNode(9);

    if (list.searchNode(data)) {
        cout << "Node inserted successfully." << endl;
    } else {
        cout << "Failed to insert node." << endl;
    }

    list.printList();

    list.deleteNode(data);

    if (!list.searchNode(data)) {
        cout << "Node deleted successfully." << endl;
    } else {
        cout << "Failed to delete node." << endl;
    }

    list.printList();

    return 0;
}
