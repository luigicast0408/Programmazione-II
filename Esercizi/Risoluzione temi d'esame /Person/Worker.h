#ifndef WORKER_H
#define WORKER_H

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Worker : public Person {
private:
    double salary;
public:
    Worker(string n, string s, double sal) : Person(n, s), salary(sal) {}
    void generateAge() { age = rand() % 48 + 18; }
    string printInformation() const  {
        return name + " " + surname + " " + to_string(age) + " " + to_string(salary);
    }
    int getType() const { return 2; }
};


#endif
