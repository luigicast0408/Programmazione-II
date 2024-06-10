#ifndef BST_H
#define BST_H
#include <iostream>
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

// Classe BST (Binary Search Tree)
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
    void deleteNodesWithAreaLessThan(double area);
    int getNumberOfElements();
    template <typename U>
    friend ostream& operator<<(ostream& out, const BST<U>& t);
};

template<typename T>
void BST<T>::printLevels(Node<T>* node, int level) const {
    if (node == nullptr) {
        cout << "_\t";
        return;
    }
    if (level == 0)
        cout << node->getValue().printShape() << "\t"; // printShape instead of just printing value
    else if (level > 0) {
        printLevels(node->getNodeLeft(), level - 1);
        printLevels(node->getNodeRight(), level - 1);
    }
}

template <typename T> // ROOT  SX DX
void BST<T>::preOrder(Node<T>* node) const {
    if (node != nullptr) {
        cout << node->getValue().printShape() << " ";
        preOrder(node->getNodeLeft());
        preOrder(node->getNodeRight());
    }
}

template<typename T>
void BST<T>::inOrder(Node<T>* node) const { // SX ROOT DX
    if (node != nullptr) {
        inOrder(node->getNodeLeft());
        cout << node->getValue().printShape() << " ";
        inOrder(node->getNodeRight());
    }
}

template <typename T> // SX DX ROOT
void BST<T>::postOrder(Node<T>* node) const {
    if (node != nullptr) {
        postOrder(node->getNodeLeft());
        postOrder(node->getNodeRight());
        cout << node->getValue().printShape() << " ";
    }
}

template<typename T>
void BST<T>::insertNode(T value) { // leaf = foglia
    Node<T>* newNode = new Node<T>(value); // create new node
    Node<T>* current = root, * parent = nullptr; // parent node
    if (!isEmpty()) {
        while (current != nullptr) { // find the position (leaf) where insert the new node
            parent = current;
            if (value < current->getValue()) {
                current = current->getNodeLeft(); // LEFT
            } else {
                current = current->getNodeRight(); // RIGHT
            }
        }
        newNode->setNodeParent(parent); // the leaf become parent
        if (value < parent->getValue()) {
            parent->setNodeLeft(newNode);
        } else {
            parent->setNodeRight(newNode);
        }
        numberOfElements++;
    } else { // BST EMPTY
        root = newNode;
        numberOfElements++;
    }
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
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
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

template <typename T>
void BST<T>::deleteNode(Node<T>* nodeToDelete) {
    if (nodeToDelete->getNodeLeft() == nullptr) {
        transplantNode(nodeToDelete, nodeToDelete->getNodeRight());
    } else if (nodeToDelete->getNodeRight() == nullptr) {
        transplantNode(nodeToDelete, nodeToDelete->getNodeLeft());
    } else {
        Node<T>* node = min(nodeToDelete->getNodeRight());
        if (node->getNodeParent() != nodeToDelete) {
            transplantNode(node, node->getNodeRight());
            node->setNodeRight(nodeToDelete->getNodeRight());
            node->getNodeRight()->setNodeParent(node);
        }
        transplantNode(nodeToDelete, node);
        node->setNodeLeft(nodeToDelete->getNodeLeft());
        node->getNodeLeft()->setNodeParent(node);
    }
    delete nodeToDelete;
}

template <typename T>
void BST<T>::deleteNode(T value) {
    Node<T>* current = root;
    while (current != nullptr && value != current->getValue()) {
        if (value > current->getValue()) {
            current = current->getNodeRight();
        } else {
            current = current->getNodeLeft();
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

template <typename T>
void BST<T>::deleteNodesWithAreaLessThan(double area) {
    vector<T> elements;
    inOrder(elements); // get all elements in order
    for (T element : elements) {
        if (element.getArea() < area) {
            deleteNode(element);
        }
    }
}

template <typename T>
int BST<T>::getNumberOfElements() {
    return numberOfElements;
}

#endif
