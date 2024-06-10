#include <iostream>
#include <string>
#include <fstream>
#include "Classes.h"
#include "BST.h"
using namespace std;

int main() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    string name, race, type;
    int age;
    BST<Animals*> BSTAnimals;

    while (in >> name >> race >> age >> type) {
        if (type == "Cane") {
            Dog* dog = new Dog(name, age, race, type, "Abbaio");
            BSTAnimals.insertNode(dog);
        } else if (type == "Gatto") {
            Cat* cat = new Cat(name, age, race, type, "Miagolio");
            BSTAnimals.insertNode(cat);
        }
    }

    cout << BSTAnimals << endl;

    // Esempio di ricerca
    cout << "Inserisci il nome dell'animale da cercare: ";
    cin >> name;

    Node<Animals*>* foundNode = BSTAnimals.recursiveSearch(name);

    if (foundNode != nullptr) {
        cout << "Animal Found : ";
        foundNode->getValue()->printAnimal();
    } else {
        cout << "Animal not found" << endl;
    }

    in.close();
    return 0;
}