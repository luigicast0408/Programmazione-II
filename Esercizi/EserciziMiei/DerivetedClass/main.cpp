#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Derivated.h"

int main(){
    Student student=Student("PIPPO","CATANIA,",10,"INf",30);
    Professor professor=Professor("PIPPO","CATANIA,",10,10);
    Derivated derivated=Derivated("PIPPO","CATANIA,",10,"INf",30,10);
    student.printStudent();
    derivated.printInfo();

}