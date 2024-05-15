#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include "Product.h"
#include "Date.h"

class FoodProduct : public Product {
private:
    Date expiryDate;
    Date productionDate;
public:
    FoodProduct();
    FoodProduct(int idProduct, std::string nameProduct, std::string descriptionProduct, double priceProduct, Date expiryDate, Date productionDate);
    Date getExpiryDate() const;
    Date getProductionDate() const;
    virtual void printInformation();
};

#endif // FOODPRODUCT_H
