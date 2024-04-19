#ifndef SCUOLACLASSI_H
#define SCUOLACLASSI_H

#include <string>
#include <vector>
#include "Studente.h"
using namespace std;

class Classi {
private:
    string nomeClasse;
    vector<Studente*> studenti;

public:
    // Costruttore
   Classi(std::string nome);

    // Distruttore
    ~Classi();

    // Metodo per ottenere il nome della classe
    string getNomeClasse();

    // Metodo per aggiungere uno studente alla classe
    void aggiungiStudente(Studente* studente);

    // Metodo per stampare le informazioni della classe
    void stampaInformazioniClasse();

    const vector<Studente *> &getStudenti();

};

#endif // SCUOLACLASSI_H
