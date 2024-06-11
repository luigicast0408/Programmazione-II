#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Student : public Person {
private:
    string schoolName;
public:
    Student(string n, string s, string sn) : Person(n, s), schoolName(sn) {}
    void generateAge() { age = rand() % 23 + 18; }
    string printInformation() const {
        return name + " " + surname + " " + to_string(age) + " " + schoolName;
    }
    int getType() const { return 1; }
};
#endif
