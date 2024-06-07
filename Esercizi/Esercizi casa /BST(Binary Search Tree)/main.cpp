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

template<typename T>
void BST<T>::printLevels(Node<T>* node, int level) const {
    if (node == nullptr) {
        cout << "_\t";
        return;
    }
    if (level == 0)
        cout << node->getValue() << "\t";
    else if (level > 0) {
        printLevels(node->getNodeLeft(), level - 1);
        printLevels(node->getNodeRight(), level - 1);
    }
}

template <typename T> // ROOT  SX DX
void BST<T>::preOrder(Node<T>* node) const {
    if (node != nullptr) { // SX left // DX right
        cout << node->getValue() << " ";
        preOrder(node->getNodeLeft());
        preOrder(node->getNodeRight());
    }
}

template<typename T>
void BST<T>::inOrder(Node<T>* node) const { // SX ROOT DX
    if (node != nullptr) {
        inOrder(node->getNodeLeft());
        cout << node->getValue() << " ";
        inOrder(node->getNodeRight());
    }
}

template <typename T> // SX DX ROOT
void BST<T>::postOrder(Node<T>* node) const {
    if (node != nullptr) {
        postOrder(node->getNodeLeft());
        postOrder(node->getNodeRight());
        cout << node->getValue() << " ";
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
        // Se deleteNode è la radice dell'albero, aggiorniamo la radice
        root = replaceNode;
    } else if (deleteNode == deleteNode->getNodeParent()->getNodeLeft()) {
        // Se deleteNode è il figlio sinistro del suo genitore
        deleteNode->getNodeParent()->setNodeLeft(replaceNode);
    } else {
        // Se deleteNode è il figlio destro del suo genitore
        deleteNode->getNodeParent()->setNodeRight(replaceNode);
    }
    if (replaceNode != nullptr) {
        // Aggiorniamo il genitore di replaceNode
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
    // Se il nodo da eliminare non ha un figlio sinistro, trapianta il nodo destro
    if (nodeToDelete->getNodeLeft() == nullptr) {
        transplantNode(nodeToDelete, nodeToDelete->getNodeRight());
    }
        // Se il nodo da eliminare non ha un figlio destro, trapianta il nodo sinistro
    else if (nodeToDelete->getNodeRight() == nullptr) {
        transplantNode(nodeToDelete, nodeToDelete->getNodeLeft());
    }
        // Se il nodo da eliminare ha entrambi i figli
    else {
        // Trova il nodo minimo nel sottoalbero destro
        Node<T>* node = min(nodeToDelete->getNodeRight());
        // Se il nodo minimo non è il figlio destro immediato del nodo da eliminare
        if (node->getNodeParent() != nodeToDelete) {
            // Trapianta il nodo minimo con il suo figlio destro
            transplantNode(node, node->getNodeRight());
            // Imposta il figlio destro del nodo minimo al figlio destro del nodo da eliminare
            node->setNodeRight(nodeToDelete->getNodeRight());
            // Aggiorna il genitore del nuovo figlio destro del nodo minimo
            node->getNodeRight()->setNodeParent(node);
        }
        // Trapianta il nodo da eliminare con il nodo minimo
        transplantNode(nodeToDelete, node);
        // Imposta il figlio sinistro del nodo minimo al figlio sinistro del nodo da eliminare
        node->setNodeLeft(nodeToDelete->getNodeLeft());
        // Aggiorna il genitore del nuovo figlio sinistro del nodo minimo
        node->getNodeLeft()->setNodeParent(node);
    }
    // Elimina il nodo da eliminare
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

int main() {
    BST<int> t;
    t.insertNode(8);
    t.insertNode(5);
    t.insertNode(10);
    t.insertNode(2);
    t.insertNode(23);
    t.insertNode(7);
    t.insertNode(6);
    t.insertNode(12);


    cout << t << endl;

    t.deleteNode(10);

    cout << t;
    t.preOrder();

}