#ifndef SELLER_H
#define SELLER_H

#include "ProductChildren.h"
#include "FoodProduct.h"
#include "Product.h"
#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

class Seller {
private:
    int idSeller;
    string name;
    string surname;
    Queue productQueue;
public:
    Seller(int idSeller, string name, string surname);
    void addProductToQueue(Product product);
    void printProducts();
    void printSeller();
    ~Seller();
};
#endif // SELLER_H
