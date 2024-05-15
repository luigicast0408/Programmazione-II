#include "ProductChildren.h"
#include <iostream>
using namespace std;

ProductChildren::ProductChildren() {}

ProductChildren::ProductChildren(int idProduct, string nameProduct, string descriptionProduct, double priceProduct, int rangeStart, int rangeEnd)
        : Product(idProduct, nameProduct, descriptionProduct, priceProduct), rangeStart(rangeStart), rangeEnd(rangeEnd) {}

int ProductChildren::getRangeStart() const { return rangeStart; }

int ProductChildren::getRangeEnd() const { return rangeEnd; }

void ProductChildren::printInformation() {
    Product::printInformation();
    cout << "RANGE START: " << rangeStart << std::endl;
    cout << "RANGE END: " << rangeEnd << std::endl;
}
