#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Person {
protected:
    string name;
    string surname;
    int age;
public:
    Person(string n, string s) : name(n), surname(s) {}
    virtual void generateAge() = 0;
    int getAge() const { return age; }
    virtual string printInformation() const = 0;
    virtual int getType() const = 0; // Added to identify the type of person
};

class Student : public Person {
private:
    string schoolName;
public:
    Student(string n, string s, string sn) : Person(n, s), schoolName(sn) {}
    void generateAge() { age = rand() % 23 + 18; }
    string printInformation() const {
        return name + " " + surname + " " + to_string(age) + " " + schoolName;
    }
    int getType() const { return 1; }
};

class Worker : public Person {
private:
    double salary;
public:
    Worker(string n, string s, double sal) : Person(n, s), salary(sal) {}
    void generateAge() { age = rand() % 48 + 18; }
    string printInformation() const  {
        return name + " " + surname + " " + to_string(age) + " " + to_string(salary);
    }
    int getType() const { return 2; }
};

class RetiredPerson : public Person {
private:
    double pension;
public:
    RetiredPerson(string n, string s, double pen) : Person(n, s), pension(pen) {}
    void generateAge()  { age = rand() % 45 + 55; }
    string printInformation() const {
        return name + " " + surname + " " + to_string(age) + " " + to_string(pension);
    }
    int getType() const override { return 3; }
};

template <typename T>
class Node {
private:
    T value;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node(T v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
    T getValue() const { return value; }
    Node* getNodeLeft() const { return left; }
    Node* getNodeRight() const { return right; }
    Node* getNodeParent() const { return parent; }
    void setNodeLeft(Node* l) { left = l; }
    void setNodeRight(Node* r) { right = r; }
    void setNodeParent(Node* p) { parent = p; }
};

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

int main() {
    srand(time(0));
    int number;
    BST<Person*> bst;
    cout << "Insert the number of Person: ";
    cin >> number;

    for (int i = 0; i < number; ++i) {
        int type;
        cout << "Insert type (1 for Student, 2 for Worker, 3 for Retired Person): ";
        cin >> type;
        if (type == 1) {
            string name, surname, nameOfSchool;
            cout << "Insert the name, surname, and name of school separated by spaces: ";
            cin >> name >> surname >> nameOfSchool;
            Student* student = new Student(name, surname, nameOfSchool);
            student->generateAge();
            bst.insertNode(student);
        } else if (type == 2) {
            string name, surname;
            double salary;
            cout << "Insert the name, surname, and salary separated by spaces: ";
            cin >> name >> surname >> salary;
            Worker* worker = new Worker(name, surname, salary);
            worker->generateAge();
            bst.insertNode(worker);
        } else if (type == 3) {
            string name, surname;
            cout << "Insert the name and surname separated by spaces: ";
            cin >> name >> surname;
            RetiredPerson* retiredPerson = new RetiredPerson(name, surname,100);
            retiredPerson->generateAge();
            bst.insertNode(retiredPerson);
        } else {
            cout << "Invalid type! Please enter 1, 2, or 3." << endl;
            --i; // to re-prompt for the same iteration
        }
    }
    cout << bst;
    bst.calculateAverageAge();

    return 0;
}
