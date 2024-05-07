#ifndef NODE
#define NODE
#include "Data.h"

template <typename T>
class Node {
public:
    Data<T> data;
    Node<T> *next;
    Node(Data<T> data, Node<T>*next);
};


#endif //PROGRAMMAZIONE_II_NODE_H
