//
// Created by Luigi Domenico Castano on 16/04/24.
//

#ifndef PET
#define PET
#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
    string name;
    string species;

public:
    Pet();
    Pet(string name, string species);
    string getName();
    void setName(string name);
    string getSpecies();
    void setSpecies(string species);
    friend std::ostream& operator<<(ostream& output, const Pet& pet);

};
#endif
