#include "Product.h"


Product::Product() : idProduct(0), nameProduct(""), descriptionProduct(""), priceProduct(0) {}

Product::Product(int idProduct, string nameProduct, string descriptionProduct, double priceProduct)
        : idProduct(idProduct), nameProduct(nameProduct), descriptionProduct(descriptionProduct), priceProduct(priceProduct) {}

Product::~Product() {}

int Product::getIdProduct() const { return idProduct; }

void Product::setIdProduct(int idProduct) { this->idProduct = idProduct; }

string Product::getNameProduct() const { return nameProduct; }

void Product::setNameProduct(std::string nameProduct) { this->nameProduct = nameProduct; }

string Product::getDescriptionProduct() const { return descriptionProduct; }

void Product::setDescriptionProduct(std::string descriptionProduct) { this->descriptionProduct = descriptionProduct; }

double Product::getPriceProduct() const { return priceProduct; }

void Product::setPriceProduct(double priceProduct) { this->priceProduct = priceProduct; }

void Product::printInformation() {
    cout << "____PRODUCT____ " << endl;
    cout << "ID PRODUCT: " << idProduct << endl;
    cout << "NAME PRODUCT: " << nameProduct << endl;
    cout << "DESCRIPTION PRODUCT: " << descriptionProduct << endl;
    cout << "PRICE PRODUCT: " << priceProduct << endl;
    cout << "____PRODUCT____ " << endl;
}
