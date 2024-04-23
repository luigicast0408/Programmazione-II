#ifndef DERIVATED_H
#define DERIVATED_H

#include "Professor.h"
#include "Student.h"
#include "string"
#include <iostream>
using namespace std;

class Derivated : public Student, public Professor {
public:
    Derivated();
    Derivated(string name, string surname, int age, string degreeCourse, int averageGrades, float salary);
    virtual ~Derivated();
    virtual void printInfo();
};

#endif // DERIVATED_H
