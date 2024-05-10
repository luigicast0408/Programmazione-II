#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node *next;
public:
    Node();
    Node(int data, Node *next);
    int getValue();
    void setValue(int value);
    Node *getNext();
    void setNext(Node *next);
};

Node::Node() {data=0;}
Node::Node(int data, Node *next): data(data), next(next) {}

int Node::getValue() {return  data;}
void Node::setValue(int value) {this->data=value;}
Node *Node::getNext() {return next;}
void Node::setNext(Node *next) {this->next=next;}


class List {
public:
    List(Node *head);

    Node *head;

    List();
    ~List();

    void addNodeHead(int value);
    void  addNodeTail(int value);
    bool searchValue(int valueSearch) const;
    bool isEmpty(Node *node);
    friend void  operator <<(ostream& out, const List& list);
};

List::List() : head(nullptr) {}
List::List(Node *head) {this->head=head;}

List::~List() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
}

bool List::isEmpty(Node *node) {
    return node == nullptr;
}

void  List::addNodeHead(int value) {
    Node *newNode = new Node(value, head);
    if (!isEmpty(head)) {
        head = newNode;

    } else {
        head = newNode;
    }
}

void List::addNodeTail(int value) {
    Node *newNode = new Node(value, nullptr);
    if (isEmpty(head)) {
        head = newNode;
    }

    Node *current = head;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }

    current->setNext(newNode);
}

bool List::searchValue(int valueSearch) const {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        if (current->getValue() == valueSearch) {
            cout << "Value (" << valueSearch << ") found at position " << count + 1 << endl;
            return true;
        }
        count++;
        current = current->getNext();
    }
    cout << "Value not found in the linked list" << endl;
    return false;
}

void  operator <<(ostream& out, const List& list){
    Node *current=list.head;
    while (current!=nullptr){
        out<<"Value-> "<<current->getValue()<<endl;
        current=current->getNext();
    }
}

int main() {
    List myList=List(nullptr);


    myList.addNodeHead(3);
    myList.addNodeHead(2);
    myList.addNodeHead(1);


    myList.addNodeTail(4);
    myList.addNodeTail(5);
    myList.addNodeTail(6);
    cout<<myList;


    myList.searchValue(3);

    myList.searchValue(7);
    return 0;
}
