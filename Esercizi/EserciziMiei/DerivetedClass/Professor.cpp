#include "Professor.h"
#include "Person.h"

Professor::Professor() {
    name="";
    surname="";
    age=0;
    salary=0.0;
}

Professor::Professor(std::string name, std::string surname, int age, float salary)
        : Person(name, surname, age), salary(salary) {}

Professor::~Professor() {}

float Professor::getSalary() {
    return salary;
}

void Professor::setSalary(float salary) {
    this->salary=salary;
}



