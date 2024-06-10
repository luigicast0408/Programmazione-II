#ifndef BST_H
#define BST_H
#include "Node.h"


template <typename T>
class BST {
private:
    Node<T>* root;
    int numberOfElements;
    void inOrder(Node<T>* node) const;
    void preOrder(Node<T>* node) const;
    void postOrder(Node<T>* node) const;
    void deleteNode(Node<T>* nodeToDelete);
    void transplantNode(Node<T>* deleteNode, Node<T>* replaceNode);
    Node<T>* min(Node<T>* node) const;
    void printLevels(Node<T>* node, int level) const;
    bool isEmpty() { return root == nullptr; }
    int calculationHeight(Node<T>* node) const;

public:
    BST() : root(nullptr), numberOfElements(0) {}
    void insertNode(T value);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void deleteNode(T value);
    template <typename U>
    friend ostream& operator<<(ostream& out, const BST<U>& t);
};


#endif
