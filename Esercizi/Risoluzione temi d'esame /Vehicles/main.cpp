#include "Classes.h"
#include "BST.h"
#include <iostream>
using namespace  std;

int main() {
    BST<Vehicles*> bst;
    Car *car1 = new Car("3", "Ferrari Testarossa", "Testarossa", 1984, "Ferrari", 3);
    Car *car2 = new Car("4", "Peugeot 208", "208", 2019, "Peugeot", 5);

    bst.insertNode(car1);
    bst.insertNode(car2);
    if (bst.searchNode("3") != nullptr){
        bst.deleteNode("3");
        cout << "Found and Deleted" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    bst.postOrder();
    return 0;
}
