#include "Person.h"
#include "Student.h"
#include "Worker.h"
#include "RetiredPerson.h"
#include "BST.h"
#include <iostream>
using namespace std;
int main() {
    srand(time(0));
    int number;
    BST<Person*> bst;
    cout << "Insert the number of Person: ";
    cin >> number;

    for (int i = 0; i < number; ++i) {
        int type;
        cout << "Insert type (1 for Student, 2 for Worker, 3 for Retired Person): ";
        cin >> type;
        if (type == 1) {
            string name, surname, nameOfSchool;
            cout << "Insert the name, surname, and name of school separated by spaces: ";
            cin >> name >> surname >> nameOfSchool;
            Student* student = new Student(name, surname, nameOfSchool);
            student->generateAge();
            bst.insertNode(student);
        } else if (type == 2) {
            string name, surname;
            double salary;
            cout << "Insert the name, surname, and salary separated by spaces: ";
            cin >> name >> surname >> salary;
            Worker* worker = new Worker(name, surname, salary);
            worker->generateAge();
            bst.insertNode(worker);
        } else if (type == 3) {
            string name, surname;
            cout << "Insert the name and surname separated by spaces: ";
            cin >> name >> surname;
            RetiredPerson* retiredPerson = new RetiredPerson(name, surname,100);
            retiredPerson->generateAge();
            bst.insertNode(retiredPerson);
        } else {
            cout << "Invalid type! Please enter 1, 2, or 3." << endl;
            --i; // to re-prompt for the same iteration
        }
    }
    cout << bst;
    bst.calculateAverageAge();

    return 0;
}
