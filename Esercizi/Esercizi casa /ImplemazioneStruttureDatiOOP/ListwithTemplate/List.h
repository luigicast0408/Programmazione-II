#ifndef LIST
#define LIST
#include "Data.h"
#include "Node.h"


template <typename T>
class List {
public:
    Node<T> *head;
    List(Node<T> *head);
    void insertNode(Data<T> data);
    void deleteNode(Data<T> data);
    bool isEmpty();
    bool searchNode(Data<T> data);
    void printList();
};
#endif //PROGRAMMAZIONE_II_LIST_H
