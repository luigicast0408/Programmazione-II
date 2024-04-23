#include "Person.h"

Person::Person() {
    name="";
    surname="";
    age=0;
}

Person::Person(string name, string surname, int age) {
    this->name=name;
    this->surname=surname;
    this->age=age;
}

string Person::getName() {
    return name;
}

void Person::setName(string name) {
    this->name=name;
}

void Person::setSurname(string surname) {
    this->surname=surname;
}

string Person::getSurname() {
    return surname;
}

int Person::getAge() {
    return age;
}

void Person::setAge(int age) {
    this->age=age;
}
