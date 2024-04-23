#ifndef STUDENT
#define STUDENT
#include "Person.h"


class  Student : public Person {
protected:
    string degreeCourse;
    int averageGrades;
public:
    Student();
    Student(string name, string surname, int age, string degreeCourse,int averageGrades);
    virtual ~Student();
    string getDegreeCourse();
    void setDegreeCourse(string degreeCourse);
    int getAverageGrades();
    void setAverageGrades(int averageGrades);
    void printStudent();
};


#endif
