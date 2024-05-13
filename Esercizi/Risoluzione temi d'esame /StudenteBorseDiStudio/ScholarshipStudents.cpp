#include "ScholarshipStudents.h"

ScholarshipStudents::ScholarshipStudents() { scholarship = nullptr; }
ScholarshipStudents::ScholarshipStudents(int id, string name, string surname, double average, Scholarship *scholarship) : Students(id, name, surname, average), scholarship(scholarship) {}

void ScholarshipStudents::printInformation() {
    Students::printInformation();
    if (scholarship && scholarship->getTotal() > 0) {
        cout << "TOTAL: " << scholarship->getTotal() << endl;
    }
}

double ScholarshipStudents::getScholarshipTotal() {
    if (scholarship != nullptr)
        return scholarship->getTotal();
    else
        return 0.0;
}

