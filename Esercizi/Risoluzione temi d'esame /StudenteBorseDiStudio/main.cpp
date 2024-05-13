#include <string>
#include "Students.h"
#include "Scholarship.h"
#include "ScholarshipStudents.h"
#include "Node.h"
#include "List.h"
#include <iostream>
using namespace std;

int main() {
    List list;

    Scholarship scholarship1 = Scholarship(800);
    ScholarshipStudents scholarshipStudent1 = ScholarshipStudents(1001, "Mario", "Rossi", 25, &scholarship1);
    Scholarship scholarship2 = Scholarship(1000);
    ScholarshipStudents scholarshipStudent2 = ScholarshipStudents(1002, "Anna", "Verdi", 26.0, &scholarship2);


    list.insertNode(scholarshipStudent1);
    list.insertNode(scholarshipStudent2);
    list.removeStudents();


    cout << "Lista degli studenti con borsa di studio:" << endl;
    list.printList();

    cout << "Somma totale delle borse di studio: " << list.calcTotScholarship() << endl;

    return 0;
}
