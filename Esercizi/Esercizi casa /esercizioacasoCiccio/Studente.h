#ifndef STUDENTE_H
#define STUDENTE_H

#include <string>
#include <vector>
#include <iostream>

class Studente {
private:
    std::string nome;
    std::string cognome;
    float mediaVoti;
    // Static vector to store all students
    static std::vector<Studente> studenti;


public:
    Studente();
    Studente(std::string nome, std::string cognome, float mediaVoti);

    std::string getNome();
    void setNome(std::string nome);

    std::string getCognome();
    void setCognome(std::string cognome);

    float getMediaVoti();
    void setMediaVoti(float media);

    static void addStudente(Studente studente);
    static Studente& getStudente(int index);

    static void printStudente(Studente studente);

    static const std::vector<Studente>& getStudenti(); // Metodo per ottenere il vettore studenti
    int size();

};

#endif // STUDENTE_H
