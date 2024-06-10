#ifndef  BST_H
#define BST_H
#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

template <typename T>
class Node {
private:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
public:
    Node(T value, Node<T>* left = nullptr, Node<T>* right = nullptr, Node<T>* parent = nullptr)
            : value(value), left(left), right(right), parent(parent) {}

    T getValue() { return value; }
    void setValue(T value) { this->value = value; }

    Node<T>* getNodeLeft() { return left; }
    void setNodeLeft(Node<T>* left) { this->left = left; }

    Node<T>* getNodeRight() { return right; }
    void setNodeRight(Node<T>* right) { this->right = right; }

    Node<T>* getNodeParent() { return parent; }
    void setNodeParent(Node<T>* parent) { this->parent = parent; }
};

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
    int calculationHeight(Node<T>* node) const;
    Node<T>* recursiveSearch(Node<T>* node, const string& name);

public:
    BST() : root(nullptr), numberOfElements(0) {}
    void insertNode(T value);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void deleteNode(T value);
    Node<T>* recursiveSearch(const string& name);
    friend bool operator<(const Animals& a1, const Animals& a2);
    friend bool operator != (const Animals& a1, const Animals& a2);
    friend bool operator == (const Animals& a1, const Animals& a2);
    template <typename U>
    friend ostream& operator<<(ostream& out, const BST<U>& t);
};

template <typename T>
void BST<T>::printLevels(Node<T>* node, int level) const {
    if (node == nullptr) {
        cout << "_\t";
        return;
    }
    if (level == 0) {
        node->getValue()->printAnimal();
    } else if (level > 0) {
        printLevels(node->getNodeLeft(), level - 1);
        printLevels(node->getNodeRight(), level - 1);
    }
}

template <typename T>
void BST<T>::preOrder(Node<T>* node) const {
    if (node != nullptr) {
        node->getValue().printAnimal();
        preOrder(node->getNodeLeft());
        preOrder(node->getNodeRight());
    }
}

template <typename T>
void BST<T>::inOrder(Node<T>* node) const {
    if (node != nullptr) {
        inOrder(node->getNodeLeft());
        node->getValue().printAnimal();
        inOrder(node->getNodeRight());
    }
}

template <typename T>
void BST<T>::postOrder(Node<T>* node) const {
    if (node != nullptr) {
        postOrder(node->getNodeLeft());
        postOrder(node->getNodeRight());
        node->getValue().printAnimal();
    }
}

template <typename T>
void BST<T>::insertNode(T value) {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = root;
    Node<T>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (*value < *(current->getValue())) { // Compare by dereferencing pointers
            current = current->getNodeLeft();
        } else {
            current = current->getNodeRight();
        }
    }

    newNode->setNodeParent(parent);
    if (parent == nullptr) {
        root = newNode;
    } else if (*value < *(parent->getValue())) { // Compare by dereferencing pointers
        parent->setNodeLeft(newNode);
    } else {
        parent->setNodeRight(newNode);
    }
    numberOfElements++;
}

template <typename T>
void BST<T>::preOrder() const { preOrder(root); }

template <typename T>
void BST<T>::inOrder() const { inOrder(root); }

template <typename T>
void BST<T>::postOrder() const { postOrder(root); }

template <typename T>
Node<T>* BST<T>::min(Node<T>* node) const {
    Node<T>* current = node;
    while (current->getNodeLeft() != nullptr) {
        current = current->getNodeLeft();
    }
    return current;
}

template <typename T>
void BST<T>::transplantNode(Node<T>* deleteNode, Node<T>* replaceNode) {
    if (deleteNode->getNodeParent() == nullptr) {
        root = replaceNode;
    } else if (deleteNode == deleteNode->getNodeParent()->getNodeLeft()) {
        deleteNode->getNodeParent()->setNodeLeft(replaceNode);
    } else {
        deleteNode->getNodeParent()->setNodeRight(replaceNode);
    }
    if (replaceNode != nullptr) {
        replaceNode->setNodeParent(deleteNode->getNodeParent());
    }
}

template <typename T>
int BST<T>::calculationHeight(Node<T>* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        int leftHeight = calculationHeight(node->getNodeLeft());
        int rightHeight = calculationHeight(node->getNodeRight());
        return max(leftHeight, rightHeight) + 1;
    }
}

template <typename T>
void BST<T>::deleteNode(Node<T>* nodeToDelete) {
    if (nodeToDelete->getNodeLeft() == nullptr) {
        transplantNode(nodeToDelete, nodeToDelete->getNodeRight());
    } else if (nodeToDelete->getNodeRight() == nullptr) {
        transplantNode(nodeToDelete, nodeToDelete->getNodeLeft());
    } else {
        Node<T>* minNode = min(nodeToDelete->getNodeRight());
        if (minNode->getNodeParent() != nodeToDelete) {
            transplantNode(minNode, minNode->getNodeRight());
            minNode->setNodeRight(nodeToDelete->getNodeRight());
            minNode->getNodeRight()->setNodeParent(minNode);
        }
        transplantNode(nodeToDelete, minNode);
        minNode->setNodeLeft(nodeToDelete->getNodeLeft());
        minNode->getNodeLeft()->setNodeParent(minNode);
    }
    delete nodeToDelete;
}

template <typename T>
void BST<T>::deleteNode(T value) {
    Node<T>* current = root;
    while (current != nullptr && *value != *(current->getValue())) { // Compare by dereferencing pointers
        if (*value < *(current->getValue())) { // Compare by dereferencing pointers
            current = current->getNodeLeft();
        } else {
            current = current->getNodeRight();
        }
    }

    if (current == nullptr) {
        cout << "The node isn't in the BST" << endl;
    } else {
        deleteNode(current);
        cout << "The node was in the BST and has been deleted" << endl;
        numberOfElements--;
    }
}

template<typename T>
Node<T>* BST<T>::recursiveSearch(Node<T>* node, const string& name) {
    if (node == nullptr || node->getValue()->getName() == name) {
        return node;
    }
    if (name < node->getValue()->getName()) {
        return recursiveSearch(node->getNodeLeft(), name);
    } else {
        return recursiveSearch(node->getNodeRight(), name);
    }
}

template<typename T>
Node<T>* BST<T>::recursiveSearch(const string& name) {
    return recursiveSearch(root, name);
}

bool operator<(const Animals& a1, const Animals& a2) {
    return a1.getName() < a2.getName();
}

ostream& operator<<(ostream& out, const Animals& animal) {
    animal.printAnimal();
    return out;
}

template <typename A>
ostream& operator<<(ostream& out, const BST<A>& bst) {
    out << "BST with height " << bst.calculationHeight(bst.root) << "\n";
    for (int i = 0; i < bst.calculationHeight(bst.root); ++i) {
        bst.printLevels(bst.root, i);
        out << "\n";
    }
    return out;
}

bool operator != (const Animals& a1, const Animals& a2) {
    return a1.getName() != a2.getName() && a1.getRace() != a2.getRace() && a1.getAge() != a2.getAge() && a1.getAnimalCall() != a2.getAnimalCall() && a1.getType() != a2.getType();
}

bool operator == (const Animals& a1, const Animals& a2) {
    return a1.getName() == a2.getName() && a1.getRace() == a2.getRace() && a1.getAge() == a2.getAge() && a1.getAnimalCall() == a2.getAnimalCall() && a1.getType() == a2.getType();
}
#endif
