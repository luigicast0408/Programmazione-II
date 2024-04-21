//
// Created by Luigi Domenico Castano on 19/04/24.
//

#ifndef LIST
#define LIST
#include "Data.h"
#include "Node.h"



class List {
public:
    Node *head;
    List();
    List(Node *head);
    void printList();
    void insertNode(Data data);
    void deleteNode(Data data);
    bool isEmpty();
    bool searchNode(Data data);
};


#endif
