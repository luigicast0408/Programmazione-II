#ifndef RETIREDPERSON_H
#define RETIREDPERSON_H

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class RetiredPerson : public Person {
private:
    double pension;
public:
    RetiredPerson(string n, string s, double pen) : Person(n, s), pension(pen) {}
    void generateAge()  { age = rand() % 45 + 55; }
    string printInformation() const {
        return name + " " + surname + " " + to_string(age) + " " + to_string(pension);
    }
    int getType() const { return 3; }
};

#endif
