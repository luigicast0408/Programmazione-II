#include "Students.h"

Students::Students() {
    id = 0;
    name = "";
    surname = "";
    average = 0.0;
}

Students::Students(int id, string name, string surname, double average) : id(id), name(name), surname(surname), average(average) {}

int Students::getId() {
    return id;
}

void Students::setId(int id) {
    this->id = id;
}

void Students::setName(string name) {
    this->name = name;
}

string Students::getSurname() {
    return surname;
}

void Students::setSurname(string surname) {
    this->surname = surname;
}

double Students::getAverage() {
    return average;
}

void Students::setAverage(double average) {
    this->average = average;
}

void Students::printInformation() {
    cout << "__________Students_____________" << endl;
    cout << "ID:" << id << endl;
    cout << "NAME:" << name << endl;
    cout << "SURNAME: " << surname << endl;
    cout << "AVERAGE: " << average << endl;
    cout << "__________Students_____________" << endl;
}