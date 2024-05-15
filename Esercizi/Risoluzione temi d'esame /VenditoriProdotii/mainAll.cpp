#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    ~Date() {}
    int getDay() const { return day; }
    void setDay(int day) { this->day = day; }
    int getMonth() const { return month; }
    void setMonth(int month) { this->month = month; }
    int getYear() const { return year; }
    void setYear(int year) { this->year = year; }
    bool checkDataExpiry();
};

bool Date::checkDataExpiry() {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = localTime->tm_year + 1900;

    int currentDate = currentYear * 10000 + currentMonth * 100 + currentDay;
    int expiryDate = year * 10000 + month * 100 + day;

    return currentDate > expiryDate;
}

class Product {
protected:
    int idProduct;
    string nameProduct;
    string descriptionProduct;
    double priceProduct;
public:
    Product() : idProduct(0), nameProduct(""), descriptionProduct(""), priceProduct(0) {}
    Product(int idProduct, string nameProduct, string descriptionProduct, double priceProduct)
            : idProduct(idProduct), nameProduct(nameProduct), descriptionProduct(descriptionProduct), priceProduct(priceProduct) {}
    virtual ~Product() {}
    int getIdProduct() const { return idProduct; }
    void setIdProduct(int idProduct) { this->idProduct = idProduct; }
    string getNameProduct() const { return nameProduct; }
    void setNameProduct(string nameProduct) { this->nameProduct = nameProduct; }
    string getDescriptionProduct() const { return descriptionProduct; }
    void setDescriptionProduct(string descriptionProduct) { this->descriptionProduct = descriptionProduct; }
    double getPriceProduct() const { return priceProduct; }
    void setPriceProduct(double priceProduct) { this->priceProduct = priceProduct; }
    virtual void printInformation();
};

void Product::printInformation() {
    cout<<"____PRODUCT____ "<<endl;
    cout << "ID PRODUCT: " << idProduct << endl;
    cout << "NAME PRODUCT: " << nameProduct << endl;
    cout << "DESCRIPTION PRODUCT: " << descriptionProduct << endl;
    cout << "PRICE PRODUCT: " << priceProduct << endl;
    cout<<"____PRODUCT____ "<<endl;
}

class FoodProduct : public Product {
private:
    Date expiryDate;
    Date productionDate;
public:
    FoodProduct() {}
    FoodProduct(int idProduct, string nameProduct, string descriptionProduct, double priceProduct, Date expiryDate, Date productionDate)
            : Product(idProduct, nameProduct, descriptionProduct, priceProduct), expiryDate(expiryDate), productionDate(productionDate) {}
    Date getExpiryDate() const { return expiryDate; }
    Date getProductionDate() const { return productionDate; }
    virtual void printInformation();
};

void FoodProduct::printInformation() {
    Product::printInformation();
    cout << "EXPIRY DATE: " << expiryDate.getDay() << "-" << expiryDate.getMonth() << "-" << expiryDate.getYear() << endl;
    cout << "PRODUCTION DATE: " << productionDate.getDay() << "-" << productionDate.getMonth() << "-" << productionDate.getYear() << endl;
}

class ProductChildren : public Product {
private:
    int rangeStart;
    int rangeEnd;
public:
    ProductChildren() {}
    ProductChildren(int idProduct, string nameProduct, string descriptionProduct, double priceProduct, int rangeStart, int rangeEnd)
            : Product(idProduct, nameProduct, descriptionProduct, priceProduct), rangeStart(rangeStart), rangeEnd(rangeEnd) {}
    int getRangeStart() const { return rangeStart; }
    int getRangeEnd() const { return rangeEnd; }
    virtual void printInformation();
};

void ProductChildren::printInformation() {
    Product::printInformation();
    cout << "RANGE START: " << rangeStart << endl;
    cout << "RANGE END: " << rangeEnd << endl;
}

template<typename T>
class Node {
private:
    T* data;
    Node<T>* next;
public:
    Node(T* data) : data(data), next(nullptr) {}
    T* getData() const { return data; }
    Node<T>* getNext() const { return next; }
    void setNext(Node<T>* next) { this->next = next; }
};

template<typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    void enqueue(T* data);
    void dequeue();
    void printInformation();
};

template<typename T>
void Queue<T>::enqueue(T* data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template<typename T>
void Queue<T>::dequeue() {
    if (!head) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
}

template<typename T>
void Queue<T>::printInformation() {
    Node<T>* current = head;
    while (current) {
        current->getData()->printInformation();
        current = current->getNext();
    }
}

class Seller {
private:
    int idSeller;
    string name;
    string surname;
    Queue<Product>* productQueue;
public:
    Seller(int idSeller, string name, string surname) : idSeller(idSeller), name(name), surname(surname), productQueue(new Queue<Product>()) {}
    void addProductToQueue(Product* product) { productQueue->enqueue(product); }
    void printProducts() { productQueue->printInformation(); }
    ~Seller() { delete productQueue; }
};

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
