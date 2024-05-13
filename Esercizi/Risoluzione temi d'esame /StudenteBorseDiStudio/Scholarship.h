#ifndef SCHOLARSHIP
#define SCHOLARSHIP
#include <iostream>
using namespace std;

class Scholarship {
    private:
        double total;
    public:
        Scholarship();
        Scholarship(double total);
        double getTotal();
        void setTotal(double total);
        void printInformation();
};


#endif //PROGRAMMAZIONE_II_SCHOLARSHIP_H
