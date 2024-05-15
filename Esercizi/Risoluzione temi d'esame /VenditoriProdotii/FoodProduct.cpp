#include "FoodProduct.h"
#include <iostream>

FoodProduct::FoodProduct() {}

FoodProduct::FoodProduct(int idProduct, std::string nameProduct, std::string descriptionProduct, double priceProduct, Date expiryDate, Date productionDate)
        : Product(idProduct, nameProduct, descriptionProduct, priceProduct), expiryDate(expiryDate), productionDate(productionDate) {}

Date FoodProduct::getExpiryDate() const { return expiryDate; }

Date FoodProduct::getProductionDate() const { return productionDate; }

void FoodProduct::printInformation() {
    Product::printInformation();
    cout << "EXPIRY DATE: " << expiryDate.getDay() << "-" << expiryDate.getMonth() << "-" << expiryDate.getYear() << std::endl;
    cout << "PRODUCTION DATE: " << productionDate.getDay() << "-" << productionDate.getMonth() << "-" << productionDate.getYear() << std::endl;
}
