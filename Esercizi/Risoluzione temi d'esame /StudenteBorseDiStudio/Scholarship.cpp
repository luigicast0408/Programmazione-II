#include "Scholarship.h"

Scholarship::Scholarship() { total = 0.0; }
Scholarship::Scholarship(double total) : total(total) {}
double Scholarship::getTotal() { return total; }
void Scholarship::setTotal(double total) { this->total = total; }

void Scholarship::printInformation() {
    cout << "_____Scholarship_________" << endl;
    cout << "TOTAL: " << total << endl;
    cout << "_____Scholarship_________" << endl;
}
