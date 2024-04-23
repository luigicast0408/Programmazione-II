#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
string name;
string surname;
int age;
public:
    Person();
    Person(string name, string surname, int age);

    string getName();
    void setName(string name);
    string getSurname();
    void setSurname(string surname);
    int getAge();
    void setAge(int age);
};
#endif
