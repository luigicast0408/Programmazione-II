#ifndef STUDENETS
#define STUDENETS
#include <iostream>
#include <string>
using namespace std;


class Students {
        private:
        int id;
        string name;
        string surname;
        double average;
        public:
        Students();
        Students(int id, string name, string surname, double average);
        int getId();
        void setId(int id);
        string getName();
        void setName(string name);
        string getSurname();
        void setSurname(string surname);
        double getAverage();
        void setAverage(double average);
        virtual void printInformation();
};


#endif //PROGRAMMAZIONE_II_STUDENETS_H
