#include "Node.h"
#include "Product.h"

Node::Node(Product data): data(data) {}
void Node::setNext(Node *next) {this->next=next;}
Node *Node::getNext() const {return next;}
Product Node::getData() const {return data;}