#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product {
protected:
    int idProduct;
    string nameProduct;
    string descriptionProduct;
    double priceProduct;
public:
    Product();
    Product(int idProduct, string nameProduct, string descriptionProduct, double priceProduct);
    virtual ~Product();
    int getIdProduct() const;
    void setIdProduct(int idProduct);
    string getNameProduct() const;
    void setNameProduct(string nameProduct);
    string getDescriptionProduct() const;
    void setDescriptionProduct(string descriptionProduct);
    double getPriceProduct() const;
    void setPriceProduct(double priceProduct);
    virtual void printInformation();
};

#endif // PRODUCT_H
