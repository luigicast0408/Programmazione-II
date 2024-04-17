#include "person.h"
#include "pet.h"
#include <iostream>
using namespace std;

// Costruttore di default
Person::Person() : name(""), surname(""), age(0) {}

// Costruttore con parametri
Person::Person(const std::string& name, const std::string& surname, int age)
        : name(name), surname(surname), age(age) {}

// Metodo per aggiungere un animale al vettore pets
void Person::addPet(const Pet& pet) {
    pets.push_back(pet);
}

// Metodo getter per il nome
std::string Person::getName() const {
    return name;
}

// Metodo setter per il nome
void Person::setName(const std::string& name) {
    this->name = name;
}

// Metodo getter per il cognome

string Person::getSurname() const {
    return surname;
}

// Metodo setter per il cognome
void Person::setSurname(const std::string& surname) {
    this->surname = surname;
}

// Metodo getter per l'età
int Person::getAge() const {
    return age;
}

// Metodo setter per l'età
void Person::setAge(int age) {
    this->age = age;
}

// Operatore di inserimento per la stampa di una persona
ostream& operator<<(std::ostream& output, const Person& person) {
    output << "Name: " << person.name << std::endl;
    output << "Surname: " << person.surname << std::endl;
    output << "Age: " << person.age << std::endl;
    output << "Pets:\n";
    for (Pet pet : person.pets) {
        output<<pet<<endl;

    }
    return output;
}
