#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <string>
#include <vector>
#include <list>

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas = 0;
    double rezVid = 0.0, rezMed = 0.0;
};

typedef std::vector<Studentas> StudentuKon;
//typedef std::list<Studentas> StudentuKon;

enum class Tvarka { Didejimo, Mazejimo };

int randPaz();
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void skaiciuotiRezultatus(Studentas& s);

#endif
