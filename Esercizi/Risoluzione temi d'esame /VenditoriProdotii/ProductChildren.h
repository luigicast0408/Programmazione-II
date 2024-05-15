#ifndef PRODUCTCHILDREN_H
#define PRODUCTCHILDREN_H

#include "Product.h"

class ProductChildren : public Product {
private:
    int rangeStart;
    int rangeEnd;
public:
    ProductChildren();
    ProductChildren(int idProduct, std::string nameProduct, std::string descriptionProduct, double priceProduct, int rangeStart, int rangeEnd);
    int getRangeStart() const;
    int getRangeEnd() const;
    virtual void printInformation();
};

#endif // PRODUCTCHILDREN_H
