#include "Data.h"
template<typename T>
Data<T>::Data(T value) {
    this->value = value;
}

template<typename T>
T Data<T>::getValue() {
    return value;
}

template<typename T>
void Data<T>::setValue(T value) {
    this->value = value;
}
