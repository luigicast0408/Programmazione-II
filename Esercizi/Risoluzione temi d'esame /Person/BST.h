#ifndef BST_H
#define BST_H
#include <iostream>
#include "Node.h"
#include "Person.h"
using namespace std;


template <typename T>
class BST {
private:
    Node<T>* root;
    int numberOfElements;
public:
    BST() : root(nullptr), numberOfElements(0) {}
    void insertNode(T value);
    void deleteNode(T value);
    void transplantNode(Node<T>* deleteNode, Node<T>* replaceNode);
    void deleteNode(Node<T>* nodeToDelete);
    Node<T>* min(Node<T>* node);
    int calculationHeight(Node<T>* node) const;
    void calculateAverageAge(Node<Person*>* node);
    void calculateAverageAge();
    template <typename A>
    friend ostream& operator<<(ostream& out, const BST<A>& bst);
    void printLevels(Node<T>* node, int level) const;
};


#endif //PROGRAMMAZIONE_II_BST_H
