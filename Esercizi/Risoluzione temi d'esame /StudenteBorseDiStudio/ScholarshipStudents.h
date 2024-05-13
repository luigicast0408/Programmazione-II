#ifndef SCHOLARSHIPSTUDENTS
#define SCHOLARSHIPSTUDENTS
#include "Scholarship.h"
#include "Students.h"

class ScholarshipStudents : public Students {
private:
    Scholarship *scholarship;
public:
    ScholarshipStudents();
    ScholarshipStudents(int id, string name, string surname, double average, Scholarship *scholarship);
    virtual void printInformation();
    double getScholarshipTotal();
};


#endif //PROGRAMMAZIONE_II_SCHOLARSHIPSTUDENTS_H
