#include "Seller.h"
#include "ProductChildren.h"
#include "FoodProduct.h"
#include "Product.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    Seller seller(1, "John", "Doe");

    ProductChildren productChildren(1, "Car", "car", 10.5, 1, 5);
    Date expiryDate(2025, 5, 15);
    Date productionDate(2025, 1, 1);
    FoodProduct foodProduct(2, "Apple", "apple", 1.5, expiryDate, productionDate);

    seller.addProductToQueue(&productChildren);
    seller.addProductToQueue(&foodProduct);

    seller.printProducts();

    return 0;
}
