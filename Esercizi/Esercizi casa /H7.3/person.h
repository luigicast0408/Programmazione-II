#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include "pet.h"

class Person {
private:
    string name;
    string surname;
    int age;
    vector<Pet> pets;

public:
    Person();
    Person(const std::string& name, const std::string& surname, int age);
    void addPet(const Pet& pet);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getSurname() const;
    void setSurname(const std::string& surname);

    int getAge() const;
    void setAge(int age);

    friend ostream& operator<<(std::ostream& output, const Person& person);
};

#endif // PERSON_H
