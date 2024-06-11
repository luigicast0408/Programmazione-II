#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string surname;
    int age;
public:
    Person(string n, string s) : name(n), surname(s) {}
    virtual void generateAge() = 0;
    int getAge() const { return age; }
    virtual string printInformation() const = 0;
    virtual int getType() const = 0; // Added to identify the type of person
};


#endif //PROGRAMMAZIONE_II_PERSON_H
