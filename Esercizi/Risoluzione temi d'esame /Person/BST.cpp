#include "BST.h"

template <typename T>
void BST<T>::insertNode(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (root == nullptr) {
        root = newNode;
        numberOfElements++;
        return;
    }

    Node<T>* current = root;
    Node<T>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value->getAge() < current->getValue()->getAge()) {
            current = current->getNodeLeft();
        } else {
            current = current->getNodeRight();
        }
    }

    if (value->getAge() < parent->getValue()->getAge()) {
        parent->setNodeLeft(newNode);
    } else {
        parent->setNodeRight(newNode);
    }
    newNode->setNodeParent(parent);
    numberOfElements++;
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
        if (value->getAge() > current->getValue()->getAge()) {
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

int countStudent = 0, countWorker = 0, countRetiredPerson = 0;
int sumStudents = 0, sumWorker = 0, sumRetiredPerson = 0;

template <typename T>
void BST<T>::calculateAverageAge(Node<Person*>* person) {
    if (person != nullptr) {
        calculateAverageAge(person->getNodeLeft());
        calculateAverageAge(person->getNodeRight());
        if (person->getValue()->getType() == 1) {
            countStudent++;
            sumStudents += person->getValue()->getAge();
        } else if (person->getValue()->getType() == 2) {
            countWorker++;
            sumWorker += person->getValue()->getAge();
        } else if (person->getValue()->getType() == 3) {
            countRetiredPerson++;
            sumRetiredPerson += person->getValue()->getAge();
        }
    }
}

template <typename T>
void BST<T>::calculateAverageAge() {
    calculateAverageAge(root);
    cout << "______PRINT THE AVERAGE OF AGE_________" << endl;
    cout << "STUDENT    WORKER     RETIRED PERSON " << endl;
    if (countStudent != 0) cout << sumStudents / countStudent << "\t";
    else cout << "N/A\t";
    if (countWorker != 0) cout << sumWorker / countWorker << "\t";
    else cout << "N/A\t";
    if (countRetiredPerson != 0) cout << sumRetiredPerson / countRetiredPerson << "\t";
    else cout << "N/A\t";
    cout << endl << "______PRINT THE AVERAGE OF AGE_________" << endl;
}

template <typename T>
void BST<T>::printLevels(Node<T>* node, int level) const {
    if (node == nullptr) return;
    if (level == 0) {
        cout << node->getValue()->printInformation() << " ";
    } else {
        printLevels(node->getNodeLeft(), level - 1);
        printLevels(node->getNodeRight(), level - 1);
    }
}

template <typename T>
Node<T>* BST<T>::min(Node<T>* node) {
    while (node->getNodeLeft() != nullptr) {
        node = node->getNodeLeft();
    }
    return node;
}

