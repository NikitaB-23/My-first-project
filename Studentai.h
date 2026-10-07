#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <string>
#include <vector>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzaminas = 0;
    double rezVid = 0.0;
    double rezMed = 0.0;
};

enum class Strategija {
    EIGERIS,
    DVIEJU,
    OPTIMALI
};

int randPaz();
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void skaiciuotiRezultatus(Studentas& s);

bool lygintiPagalPavarde(const Studentas& a, const Studentas& b);
bool lygintiPagalVarda(const Studentas& a, const Studentas& b);
bool lygintiPagalGalutini(const Studentas& a, const Studentas& b);

#endif // STUDENTAS_H_INCLUDED
