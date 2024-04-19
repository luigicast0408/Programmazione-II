#include "Scuola.h"
#include <string>
#include <iostream>
using namespace std;

Scuola::Scuola() {
    nome="";
    via="";
}
Scuola::Scuola(string nome, string via) {
    this->nome=nome;
    this->via=via;
}

string Scuola::getNome() {
    return nome;
}

void Scuola::setNome(std::string nome) {
    this->nome=nome;
}

string Scuola::getVia() {
    return via;
}

void Scuola::setVia(string via) {
    this->via=via;
}

