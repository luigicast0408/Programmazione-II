#include "pet.h"
#include <iostream>
using namespace std;

// Costruttore di default
Pet::Pet() {
    name="";
    species="";
}

// Costruttore con parametri
Pet::Pet(string name, string species) {
    this->name=name;
    this->species=species;
}

// Metodo getter per il nome
string Pet::getName()  {
    return name;
}

// Metodo setter per il nome
void Pet::setName(string name) {
    this->name = name;
}

// Metodo getter per la specie
string Pet::getSpecies(){
    return species;
}

// Metodo setter per la specie
void Pet::setSpecies(string species) {
    this->species = species;
}

// Operatore di inserimento per la stampa di un animale
ostream& operator<<(ostream& output, const Pet& pet) {
    output << "Name: " << pet.getName() << endl;
    output << "Species: " << pet.getSpecies() << endl;
    return output;
}
