#include "List.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

List::List() {
    head=NULL;
}

List::List(Node *head) {
    this->head=head;
}

void List::printList() {
    cout<<"_________PRINT LIST_________"<<endl;
    Node *currentNode=head;
    while (currentNode!=NULL){
        cout<<"Node->"<<currentNode->data.getValue()<<endl;
    currentNode=currentNode->next;
    }
    cout<<"_________PRINT LIST_________"<<endl;
}

void List::deleteNode(Data data) {
    Node *currentNode = head;
    Node *previus = NULL;
    while (currentNode != NULL && currentNode->data.getValue() != data.getValue()) {
        previus = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode != NULL) { //elemento esiste nella lista
        if (previus) // e non e' la testa della lista
            previus->next = currentNode->next; // aggiorna il link..
        else
            head = currentNode->next; // aggiorna il puntatore al primo elemento
        delete currentNode;
    }
}

bool List::isEmpty() {
    return head == NULL ? true: false;
}

void List::insertNode(Data data) {
    int count=1;
    Node *newNode=new Node(data,nullptr);
    if (isEmpty()){
        head=newNode;
    } else{
        Node *currentNode=head, *prev=nullptr;
        currentNode->data.setValue(count*1);
        while (currentNode != nullptr && currentNode->data.getValue()<newNode->data.getValue()) {
            prev = currentNode;
            currentNode = currentNode->next;
        }
        if(prev!=NULL)
            prev->next = newNode;
        else
            head = newNode; // inserimento in testa

        // se current == NULL, l'elemento sara' aggiunto in coda alla lista
        if(currentNode!=NULL)
            newNode->next = currentNode;
    }
    count++;
}

bool List::searchNode(Data data) {
    Node *currentNode = head;
    int count = 0;

    while (currentNode != nullptr) {
        if (currentNode->data.getValue() == data.getValue()) {
            cout << "Index: " << count << endl;
            return true;
        }
        currentNode = currentNode->next;
        count++;
    }

    cout << "Value not found" << endl;
    return false;
}

