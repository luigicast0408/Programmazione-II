#include "Derivated.h"
#include "Professor.h"
#include "Student.h"
#include "Person.h"


Derivated::Derivated() {
    // Inizializzazione dei membri delle classi base
}

Derivated::Derivated(string name, string surname, int age, string degreeCourse, int averageGrades, float salary):
    Student(name, surname, age, degreeCourse, averageGrades), Professor(name, surname, age, salary) {}

Derivated::~Derivated() {}


void Derivated::printInfo() {
    cout << "Name: " <<Student::getName() <<endl;
    cout << "Surname: " << Student::getSurname() << endl;
    cout << "Age: " << Student::getAge() << std::endl;
    cout << "Degree Course: " << Student::getDegreeCourse() << endl;
    cout << "Average Grades: " << Student::getAverageGrades() << endl;
    cout << "Salary: " << Professor::getSalary() << endl;
}
