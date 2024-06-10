#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
using namespace std;

class Animals {
        protected:
        string name;
        int age;
        string race;
        string type;
        public:
        Animals(string name, int age, string race, string type)
        : name(name), age(age), race(race), type(type) {}

        string getName() const { return name; }
        void setName(string name) { Animals::name = name; }

        int getAge() const { return age; }
        void setAge(int age) { Animals::age = age; }

        string getRace() const { return race; }
        void setRace(string race) { Animals::race = race; }

        string getType() const { return type; }
        void setType(string type) { Animals::type = type; }

        virtual string getAnimalCall() const { return ""; }
        virtual void printAnimal() const { cout << ""; }

        virtual ~Animals() {}
};

class Dog : public Animals {
private:
    string animalCall;
public:
    Dog(string name, int age, string race, string type, string animalCall)
            : Animals(name, age, race, type), animalCall(animalCall) {}

    string getAnimalCall() const { return animalCall; }
    void printAnimal() const  {
        cout << "Dog: Name: " << name << " Age: " << age
             << " Race: " << race << " Type: " << type
             << " Call: " << animalCall << endl;
    }
};

class Cat : public Animals {
private:
    string animalCall;
public:
    Cat(string name, int age, string race, string type, string animalCall)
            : Animals(name, age, race, type), animalCall(animalCall) {}

    string getAnimalCall() const { return animalCall; }
    void printAnimal() const {
        cout << "Cat: Name: " << name << " Age: " << age
             << " Race: " << race << " Type: " << type
             << " Call: " << animalCall << endl;
    }
};

#endif
