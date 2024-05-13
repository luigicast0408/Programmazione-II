#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Students {
private:
    int id;
    string name;
    string surname;
    double average;
public:
    Students();
    Students(int id, string name, string surname, double average);
    int getId();
    void setId(int id);
    string getName();
    void setName(string name);
    string getSurname();
    void setSurname(string surname);
    double getAverage();
    void setAverage(double average);

    virtual void printInformation();
};

Students::Students() {
    id = 0;
    name = "";
    surname = "";
    average = 0.0;
}

Students::Students(int id, string name, string surname, double average) : id(id), name(name), surname(surname), average(average) {}

int Students::getId() {
    return id;
}

void Students::setId(int id) {
    this->id = id;
}

void Students::setName(string name) {
    this->name = name;
}

string Students::getSurname() {
    return surname;
}

void Students::setSurname(string surname) {
    this->surname = surname;
}

double Students::getAverage() {
    return average;
}

void Students::setAverage(double average) {
    this->average = average;
}

void Students::printInformation() {
    cout << "__________Students_____________" << endl;
    cout << "ID:" << id << endl;
    cout << "NAME:" << name << endl;
    cout << "SURNAME: " << surname << endl;
    cout << "AVERAGE: " << average << endl;
    cout << "__________Students_____________" << endl;
}

class Scholarship {
private:
    double total;
public:
    Scholarship();
    Scholarship(double total);
    double getTotal();
    void setTotal(double total);
    void printInformation();
};

Scholarship::Scholarship() { total = 0.0; }
Scholarship::Scholarship(double total) : total(total) {}
double Scholarship::getTotal() { return total; }
void Scholarship::setTotal(double total) { this->total = total; }

void Scholarship::printInformation() {
    cout << "_____Scholarship_________" << endl;
    cout << "TOTAL: " << total << endl;
    cout << "_____Scholarship_________" << endl;
}

class ScholarshipStudents : public Students {
private:
    Scholarship *scholarship;
public:
    ScholarshipStudents();
    ScholarshipStudents(int id, string name, string surname, double average, Scholarship *scholarship);
    virtual void printInformation();
    double getScholarshipTotal();
};

ScholarshipStudents::ScholarshipStudents() { scholarship = nullptr; }
ScholarshipStudents::ScholarshipStudents(int id, string name, string surname, double average, Scholarship *scholarship) : Students(id, name, surname, average), scholarship(scholarship) {}

void ScholarshipStudents::printInformation() {
    Students::printInformation();
    if (scholarship && scholarship->getTotal() > 0) {
        cout << "TOTAL: " << scholarship->getTotal() << endl;
    }
}

double ScholarshipStudents::getScholarshipTotal() {
    if (scholarship != nullptr)
        return scholarship->getTotal();
    else
        return 0.0;
}

class Node {
private:
    ScholarshipStudents *scholarshipStudents;
    Node *next;
public:
    Node();
    Node(ScholarshipStudents *scholarshipStudents, Node *next);
    Node *getNext();
    void setNext(Node *next);
    ScholarshipStudents *getScholarshipStudent();
};

Node::Node() : scholarshipStudents(nullptr), next(nullptr) {}
Node::Node(ScholarshipStudents *scholarshipStudents, Node *next) : scholarshipStudents(scholarshipStudents), next(next) {}
Node *Node::getNext() { return next; }
void Node::setNext(Node *next) { this->next = next; }
ScholarshipStudents *Node::getScholarshipStudent() { return scholarshipStudents; }

class List{
public:
    Node *head;
    List(): head(nullptr){}
    List(Node *head) : head(head){}
    bool isEmpty(){return  head==nullptr;};
    void insertNode(ScholarshipStudents& scholarshipStudent);
    void deleteNode(ScholarshipStudents& scholarshipStudent);
    void printList();
    void readWriteFile();
    double calcTotScholarship();
    void removeStudents();
};

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




int main() {
    List list;

    Scholarship scholarship1 = Scholarship(800);
    ScholarshipStudents scholarshipStudent1 = ScholarshipStudents(1001, "Mario", "Rossi", 25, &scholarship1);
    Scholarship scholarship2 = Scholarship(1000);
    ScholarshipStudents scholarshipStudent2 = ScholarshipStudents(1002, "Anna", "Verdi", 26.0, &scholarship2);


    list.insertNode(scholarshipStudent1);
    list.insertNode(scholarshipStudent2);
    list.removeStudents();


    cout << "Lista degli studenti con borsa di studio:" << endl;
    list.printList();

    // Calcolo e stampa della somma totale delle borse di studio
    cout << "Somma totale delle borse di studio: " << list.calcTotScholarship() << endl;

    return 0;
}
