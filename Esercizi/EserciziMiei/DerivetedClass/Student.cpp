#include "Student.h"
Student::Student() {
    name="";
    surname="";
    age=0;
    degreeCourse="";
    averageGrades=0.0;
}


Student::Student(std::string name, std::string surname, int age, std::string degreeCourse, int averageGrades)
        : Person(name, surname, age), degreeCourse(degreeCourse), averageGrades(averageGrades) {}

Student::~Student() {}

string Student::getDegreeCourse() {
    return degreeCourse;
}

void Student::setDegreeCourse(string degreeCourse) {
    this->degreeCourse=degreeCourse;
}

int Student::getAverageGrades() {
    return averageGrades;
}

void Student::setAverageGrades(int averageGrades) {
    this->averageGrades=averageGrades;
}

void Student::printStudent() {
    cout<<"Name"<<name<<endl;
    cout<<"Surname"<<surname<<endl;
    cout<<"Age"<<age<<endl;
}