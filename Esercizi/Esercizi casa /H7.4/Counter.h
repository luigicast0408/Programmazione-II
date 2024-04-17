#ifndef PROGRAMMAZIONE_II_COUNTER_H
#define PROGRAMMAZIONE_II_COUNTER_H

class Counter {
private:
    int counter;

public:
    Counter();
    Counter(int counter);
    int getCounter();
    void setCounter();

    void increase();
    void decrease();

    void increase(int increaseBy);
    void decrease(int decreaseBy);
};


#endif //PROGRAMMAZIONE_II_COUNTER_H
