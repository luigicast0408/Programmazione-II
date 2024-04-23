//
// Created by Luigi Domenico Castano on 23/04/24.
//

#ifndef PROFESSOR
#define PROFESSOR
#include <string>
#include "Person.h"


class Professor : public Person {
protected:
    float salary;
public:
    Professor();
    Professor(string name, string surname, int age,float salary);
    virtual ~Professor();

    float getSalary();
    void setSalary(float salary);
};


#endif
