//
// Created by Luigi Domenico Castano on 18/04/24.
//

#ifndef SCUOLA
#define SCUOLA
#include <string>
#include <iostream>
using namespace std;
class Scuola{
private:
    string nome;
    string via;

public:
    Scuola();
    Scuola(string nome, string via);
    string getNome();
    void setNome(string nome);

    string getVia();
    void setVia(string via);
};


#endif
