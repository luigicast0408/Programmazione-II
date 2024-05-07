#include <iostream>
#include "Data.h"
#include "Node.h"
#include "List.h"
using namespace std;

int main() {
    Node<int>* head = nullptr;
    List<int> list = List<int>(head);

    Data<int> data = Data<int>(2);
    list.insertNode(data);

    // Controllo se il nodo è stato inserito correttamente
    if (list.searchNode(data)) {
        cout << "Node inserted successfully." << endl;
    } else {
        cout << "Failed to insert node." << endl;
    }

    list.printList();

    // Elimina il nodo
    list.deleteNode(data);

    // Controlla se il nodo è stato eliminato correttamente
    if (!list.searchNode(data)) {
        cout << "Node deleted successfully." << endl;
    } else {
        cout << "Failed to delete node." << endl;
    }

    list.printList();

    return 0;
}