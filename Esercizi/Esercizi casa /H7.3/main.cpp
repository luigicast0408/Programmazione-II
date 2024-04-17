#include <vector>
#include "person.h"
#include "pet.h"
#include <iostream>
using namespace std;

int main() {
    // Creiamo alcuni animali
    Pet dog("Buddy", "Dog");
    Pet cat("Whiskers", "Cat");

    // Creiamo una persona e aggiungiamo gli animali
    Person person("Alice", "Smith", 30);
    person.addPet(dog);
    person.addPet(cat);

    // Stampiamo le informazioni sulla persona
    cout << "Person Information:\n" << person << std::endl;

    return 0;
}
