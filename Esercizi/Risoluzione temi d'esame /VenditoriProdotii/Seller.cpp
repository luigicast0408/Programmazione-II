#include "Seller.h"
#include <iostream>

Seller::Seller(int idSeller, std::string name, std::string surname) : idSeller(idSeller), name(name), surname(surname), productQueue(new Queue<Product>()) {}

void Seller::addProductToQueue(Product* product) { productQueue->enqueue(product); }

void Seller::printProducts() { productQueue->printInformation(); }

Seller::~Seller() { delete productQueue; }
