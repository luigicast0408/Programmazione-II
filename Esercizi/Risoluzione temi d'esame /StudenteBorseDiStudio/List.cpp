#include "List.h"

void List::printList() {
    Node *current=head;
    while (current!=nullptr){
        current->getScholarshipStudent()->printInformation();
        current=current->getNext();
    }
}

void List::insertNode(ScholarshipStudents& scholarshipStudent) {
    Node * newNode= new Node(&scholarshipStudent,nullptr);
    if (isEmpty()){
        head=newNode;
    } else{
        Node* current=head; Node* prev=nullptr;
        while (current!= nullptr && current->getScholarshipStudent()->getId()!=scholarshipStudent.getId()){
            prev=current;
            current=current->getNext();
        }
        if (current == nullptr) {
            prev->setNext(newNode);
        } else {
            if (prev == nullptr) {
                newNode->setNext(head);
                head = newNode;
            } else {
                prev->setNext(newNode);
                newNode->setNext(current);
            }
        }
    }
}

void List::deleteNode(ScholarshipStudents &scholarshipStudent) {
    if (isEmpty()){
        return;
    }
    Node *current=head; Node *prev=nullptr;
    while (current!=nullptr  && current->getScholarshipStudent()->getId()!=scholarshipStudent.getId()){
        prev=current;
        current=current->getNext();
    }
    if(current!=NULL){ //elemento esiste nella lista
        if(prev) // e non e' la testa della lista
            prev->setNext(current->getNext()); // aggiorna il link..
        else
            head = current->getNext(); // aggiorna il puntatore al primo elemento
        delete current;
    }
}

void List::removeStudents() {
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->getScholarshipStudent()->getAverage() < 25) {
            cout << "____STUDENT REMOVED___" << endl;
            current->getScholarshipStudent()->printInformation();
            Node *temp = current;
            current = current->getNext(); // Move current to the next node before deletion
            deleteNode(*temp->getScholarshipStudent());
            cout << "__STUDENT REMOVED__" << endl;
        } else {
            prev = current;
            current = current->getNext();
        }
    }
}


double List::calcTotScholarship() {
    double total = 0.0;
    Node *current = head;

    while (current != nullptr) {
        total += current->getScholarshipStudent()->getScholarshipTotal();
        current = current->getNext();
    }

    return total;
}

