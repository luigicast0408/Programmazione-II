#include <iostream>
#include "Data.h"
#include "Node.h"
#include "List.h"
using namespace std;

int main(){
    Data data=Data();
    Node head=Node(data,nullptr);
    List list=List();
    list.insertNode(data);
    list.insertNode(data);
    list.insertNode(data);
    list.printList();
    Data data1=(1);
    list.deleteNode(data1);
    list.printList();
    Data data2=Data(1);
    list.searchNode(data2);
    return 0;
}
