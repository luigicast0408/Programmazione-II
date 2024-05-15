#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    ~Date();
    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    bool checkDataExpiry();
};

#endif // DATE_H
