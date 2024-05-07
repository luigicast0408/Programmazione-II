//
// Created by Luigi Domenico Castano on 07/05/24.
//

#include "List.h"
#include <iostream>
using namespace std;

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
