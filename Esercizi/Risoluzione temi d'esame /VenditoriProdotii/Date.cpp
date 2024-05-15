#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::~Date() {}

int Date::getDay() const { return day; }

void Date::setDay(int day) { this->day = day; }

int Date::getMonth() const { return month; }

void Date::setMonth(int month) { this->month = month; }

int Date::getYear() const { return year; }

void Date::setYear(int year) { this->year = year; }

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