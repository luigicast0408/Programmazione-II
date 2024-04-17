#include <string>
#include <cmath>
#include "Counter.h"
#include <iostream>
using namespace std;

int main() {
    Counter counter=Counter(10);
    counter.increase();
    cout<<counter.getCounter()<<endl;

    counter.decrease();
    cout<<counter.getCounter()<<endl;

    counter.increase(10);
    cout<<counter.getCounter()<<endl;

    counter.decrease(10);
    cout<<counter.getCounter()<<endl;
}