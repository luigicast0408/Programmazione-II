#ifndef BST_h
#define BST_h
#include "Classes.h"
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

    T getValue() {
        return value;
    }

    void setValue(T value) {
        this->value = value;
    }

    Node<T>* getNodeLeft() {
        return left;
    }

    void setNodeLeft(Node<T>* left) {
        this->left = left;
    }

    Node<T>* getNodeRight() {
        return right;
    }

    void setNodeRight(Node<T>* right) {
        this->right = right;
    }

    Node<T>* getNodeParent() {
        return parent;
    }

    void setNodeParent(Node<T>* parent) {
        this->parent = parent;
    }
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
    Node<T>* searchNode(const string& idVehicles, Node<T>* nodeToSearch);
    void printLevels(Node<T>* node, int level) const;
    bool isEmpty() const { return root == nullptr; }
    int calculationHeight(Node<T>* node) const;

public:
    BST() : root(nullptr), numberOfElements(0) {}

    void insertNode(T value);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void deleteNode(const string& idVehicles);
    Node<T>* searchNode(const string& idVehicles);

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
        cout << node->getValue()->printInformation() << "\t";
    else if (level > 0) {
        printLevels(node->getNodeLeft(), level - 1);
        printLevels(node->getNodeRight(), level - 1);
    }
}

template <typename T>
void BST<T>::preOrder(Node<T>* node) const {
    if (node != nullptr) {
        cout << node->getValue()->printInformation() << " ";
        preOrder(node->getNodeLeft());
        preOrder(node->getNodeRight());
    }
}

template<typename T>
void BST<T>::inOrder(Node<T>* node) const {
    if (node != nullptr) {
        inOrder(node->getNodeLeft());
        cout << node->getValue()->printInformation() << " ";
        inOrder(node->getNodeRight());
    }
}

template <typename T>
void BST<T>::postOrder(Node<T>* node) const {
    if (node != nullptr) {
        postOrder(node->getNodeLeft());
        postOrder(node->getNodeRight());
        cout << node->getValue()->printInformation() << " ";
    }
}

template<typename T>
void BST<T>::insertNode(T value) {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = root, * parent = nullptr;

    if (!isEmpty()) {
        while (current != nullptr) {
            parent = current;
            if (*value < *(current->getValue())) {
                current = current->getNodeLeft();
            } else {
                current = current->getNodeRight();
            }
        }
        newNode->setNodeParent(parent);
        if (*value < *(parent->getValue())) {
            parent->setNodeLeft(newNode);
        } else {
            parent->setNodeRight(newNode);
        }
        numberOfElements++;
    } else {
        root = newNode;
        numberOfElements++;
    }
}

template <typename T>
void BST<T>::preOrder() const {
    preOrder(root);
}

template <typename T>
void BST<T>::inOrder() const {
    inOrder(root);
}

template <typename T>
void BST<T>::postOrder() const {
    postOrder(root);
}

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
    delete nodeToDelete->getValue();
    delete nodeToDelete;
}

template <typename T>
Node<T>* BST<T>::searchNode(const string& idVehicle) {
    return searchNode(idVehicle, root);
}

template <typename T>
Node<T>* BST<T>::searchNode(const string& idVehicle, Node<T>* nodeToSearch) {
    Node<T>* current = nodeToSearch;
    while (current != nullptr && current->getValue()->getIdVehicles() != idVehicle) {
        if (idVehicle < current->getValue()->getIdVehicles()) {
            current = current->getNodeLeft();
        } else {
            current = current->getNodeRight();
        }
    }
    return current;
}

template <typename T>
void BST<T>::deleteNode(const string& idVehicles) {
    Node<T>* nodeToDelete = searchNode(idVehicles);
    if (nodeToDelete != nullptr) {
        deleteNode(nodeToDelete);
        cout << "The node was in the BST and has been deleted" << endl;
        numberOfElements--;
    } else {
        cout << "The node isn't in the BST" << endl;
    }
}

bool operator<(const Vehicles& v1, const Vehicles& v2) {
    return v1.getIdVehicles() < v2.getIdVehicles();
}

bool operator>(const Vehicles& v1, const Vehicles& v2) {
    return v1.getIdVehicles() > v2.getIdVehicles();
}

bool operator==(const Vehicles& v1, const Vehicles& v2) {
    return v1.getIdVehicles() == v2.getIdVehicles();
}

bool operator!=(const Vehicles& v1, const Vehicles& v2) {
    return v1.getIdVehicles() != v2.getIdVehicles();
}
#endif
