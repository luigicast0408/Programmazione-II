#ifndef LIST
#define LIST
#include <iostream>
#include "Node.h"
#include "ScholarshipStudents.h"
using namespace std;

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
#endif