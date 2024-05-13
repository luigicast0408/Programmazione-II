#ifndef NODE
#define NODE
#include "ScholarshipStudents.h"

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


#endif //PROGRAMMAZIONE_II_NODE_H
