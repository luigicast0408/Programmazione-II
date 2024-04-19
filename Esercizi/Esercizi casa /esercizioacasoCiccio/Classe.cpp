#include "Classe.h"
#include <iostream>
using namespace std;

Classi::Classi(string nome) {
    this->nomeClasse=nome;
}

Classi::~Classi() {}

void Classi::aggiungiStudente(Studente *studente) {
    studenti.push_back(studente);
}

void Classi::stampaInformazioniClasse() {
    cout<<"Classe: "<<nomeClasse<<endl;
}


const vector<Studente *> &Classi::getStudenti() {
    return studenti;
}

void Classi::setNomeClasse( string &nomeClasse) {
    this->nomeClasse = nomeClasse;
}
