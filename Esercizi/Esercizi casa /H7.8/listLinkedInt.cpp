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
    int deleteNode(int valueDelete);
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

int List::deleteNode(int valueDelete) {
    Node *current = head;
    Node *prev = nullptr;

    if (isEmpty(head)) {
        return -1; // List is empty
    } else {
        while (current != nullptr && current->getValue() != valueDelete) {
            prev = current;
            current = current->getNext();
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->setNext(current->getNext());
                delete current;
            } else {
                head = current->getNext();
                delete current;
            }
            return 0;
        } else {
            return -1;
        }
    }
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

    if (int result=myList.deleteNode(3) ==0){
        cout<<"The node is delete"<<endl;
    } else{
        cout<<"The node isn't delete"<<endl;
    }
    cout<<myList;
}