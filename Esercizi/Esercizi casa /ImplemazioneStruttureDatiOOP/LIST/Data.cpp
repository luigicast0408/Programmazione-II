
#include "Data.h"
#include <iostream>
using namespace std;

Data::Data() {
    value=0;
}

Data::Data(int value) {
    this->value=value;
}

int Data::getValue() {
    return value;
}

void Data::setValue(int value) {
    this->value=value;
}
