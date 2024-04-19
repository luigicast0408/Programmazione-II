#include <iostream>
#include "Classe.h"
#include "Studente.h"

int main() {
    // Creazione di una classe
    Classi* classe = new Classi("1A");

    // Creazione di alcuni studenti
    auto* student1 = new Studente("Mario","Rossi",10);
    auto* student2 = new Studente("Luca", "Di termine",5);
    auto* student3 = new Studente("pippo","Ciccio",3);

    // Aggiunta degli studenti alla classe
    classe->aggiungiStudente(student1);
    classe->aggiungiStudente(student2);
    classe->aggiungiStudente(student3);

    // Stampa delle informazioni della classe
    classe->stampaInformazioniClasse();

    // Stampa delle informazioni di ogni studente associato alla classe
    std::cout << "Elenco degli studenti della classe " << classe->getNomeClasse() << ":" << std::endl;
    const std::vector<Studente*>& studentiClasse = classe->getStudenti();
    for (Studente* studente : studentiClasse) {
        Studente::printStudente(*studente);
    }

    // Deallocazione della memoria
    delete classe; // Il distruttore di classe libererà la memoria per gli studenti
    delete student1;
    delete student2;
    delete student3;

    return 0;
}
