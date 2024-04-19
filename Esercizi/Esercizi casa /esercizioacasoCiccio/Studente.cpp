#include "Studente.h"

std::vector<Studente> Studente::studenti;

Studente::Studente() {
    nome = "";
    cognome = "";
    mediaVoti = 0.0;
}

Studente::Studente(std::string nome, std::string cognome, float mediaVoti) {
    this->nome = nome;
    this->cognome = cognome;
    this->mediaVoti = mediaVoti;
}

std::string Studente::getNome() {
    return nome;
}

void Studente::setNome(std::string nome) {
    this->nome = nome;
}

std::string Studente::getCognome() {
    return cognome;
}

void Studente::setCognome(std::string cognome) {
    this->cognome = cognome;
}

float Studente::getMediaVoti() {
    return mediaVoti;
}

void Studente::setMediaVoti(float media) {
    mediaVoti = media;
}

void Studente::addStudente(Studente studente) {
    studenti.push_back(studente);
}

Studente& Studente::getStudente(int index) {
    return studenti[index];
}

void Studente::printStudente(Studente studente) {
    std::cout << "_________________________________" << std::endl;
    std::cout << "Nome: " << studente.nome << std::endl;
    std::cout << "Cognome: " << studente.cognome << std::endl;
    std::cout << "Media voti: " << studente.mediaVoti << std::endl;
    std::cout << "_________________________________" << std::endl;
}

int Studente::size() {
    return studenti.size();
}


const std::vector<Studente> &Studente::getStudenti() {
    return studenti;
}