//
// Created by Luigi Domenico Castano on 13/05/24.
//

#include "Node.h"

Node::Node() : scholarshipStudents(nullptr), next(nullptr) {}
Node::Node(ScholarshipStudents *scholarshipStudents, Node *next) : scholarshipStudents(scholarshipStudents), next(next) {}
Node *Node::getNext() { return next; }
void Node::setNext(Node *next) { this->next = next; }
ScholarshipStudents *Node::getScholarshipStudent() { return scholarshipStudents; }

