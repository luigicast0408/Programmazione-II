//
// Created by Luigi Domenico Castano on 19/04/24.
//

#include "Node.h"
#include <iostream>
using namespace std;
Node::Node() {
    data=0;
    next=nullptr;
}

Node::Node(Data data, Node *next) {
    this->data=data;
    this->next=next;
}
