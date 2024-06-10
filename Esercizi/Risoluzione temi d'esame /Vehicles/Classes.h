#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>

using namespace std;

class Vehicles {
protected:
    string idVehicles;
    string name;
    string model;
    int yearOfManufacture;
    string brand;

public:
    Vehicles(string idVehicles, string name, string model, int yearOfManufacture, string brand)
            : idVehicles(idVehicles), name(name), model(model), yearOfManufacture(yearOfManufacture), brand(brand) {}

    virtual ~Vehicles() {}

    string getIdVehicles() const {
        return idVehicles;
    }

    void setIdVehicles(string idVehicles) {
        Vehicles::idVehicles = idVehicles;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        Vehicles::name = name;
    }

    string getModel() const {
        return model;
    }

    void setModel(string model) {
        Vehicles::model = model;
    }

    int getYearOfManufacture() const {
        return yearOfManufacture;
    }

    void setYearOfManufacture(int yearOfManufacture) {
        Vehicles::yearOfManufacture = yearOfManufacture;
    }

    string getBrand() const {
        return brand;
    }

    void setBrand(string brand) {
        Vehicles::brand = brand;
    }

    virtual string printInformation() const = 0;
};

class Car : public Vehicles {
private:
    int numberOfDoor;

public:
    Car(string idVehicles, string name, string model, int yearOfManufacture, string brand, int numberOfDoor)
            : Vehicles(idVehicles, name, model, yearOfManufacture, brand), numberOfDoor(numberOfDoor) {}

    int getNumberOfDoor() const {
        return numberOfDoor;
    }

    string printInformation() const {
        return "CAR: Name: " + name + " Model: " + model + " Year of Manufacture: " + to_string(yearOfManufacture) + " Brand: " + brand + " Number of Doors: " + to_string(numberOfDoor);
    }

    friend ostream& operator<<(ostream& os, const Car& c) {
        os << c.printInformation() << endl;
        return os;
    }
};
#endif
