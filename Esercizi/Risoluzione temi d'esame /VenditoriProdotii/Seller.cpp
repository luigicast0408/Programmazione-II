#include "Seller.h"
#include <iostream>

Seller::Seller(int idSeller, string name, string surname) : idSeller(idSeller), name(name), surname(surname) {}

void Seller::addProductToQueue(Product product) { productQueue.enqueue(product); }

void Seller::printProducts() { productQueue.printInformation(); }

void Seller::printSeller() {
    cout<<"Id: "<<idSeller;
    cout<<"Name:  "<<name<<endl;
    cout<<"Surname: "<<surname<<endl;
}

Seller::~Seller() {}
