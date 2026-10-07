#ifndef FAILAI_H_INCLUDED
#define FAILAI_H_INCLUDED

#include "Studentas.h"
#include <string>
#include <vector>

double generuotiFaila(const std::string& failoVardas, int n);

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas);

void isvestiIFaila(const std::string& failoVardas,
                   const std::vector<Studentas>& studentai,
                   int pasirinkimas);

#endif // FAILAI_H_INCLUDED
