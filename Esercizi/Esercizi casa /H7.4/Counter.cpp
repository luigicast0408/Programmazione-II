//
// Created by Luigi Domenico Castano on 17/04/24.
//

#include "Counter.h"
#include <iostream>
using namespace std;

Counter::Counter() {
    counter=0;
    counter++;
}

Counter::Counter(int counter) {
    this->counter=counter;
}

int Counter::getCounter() {
    return counter;
}

void Counter::setCounter() {
    this->counter=counter;
}

void Counter::increase() {
    counter++;
}

void Counter::decrease() {
    counter--;
}

void Counter::increase(int increaseBy) {
    if (increaseBy>=0){
        counter+=increaseBy;
    }
}

void Counter::decrease(int decreaseBy) {
    if (decreaseBy>=0){
        counter-=decreaseBy;
    }
}