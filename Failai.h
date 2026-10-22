#ifndef FAILAI_H_INCLUDED
#define FAILAI_H_INCLUDED
#include "Studentas.h"
#include <string>

double generuotiFaila(const std::string& failoVardas, int n);
StudentuKon nuskaitytiIsFailo(const std::string& failoVardas);
void isvestiIFaila(const std::string& failoVardas, const StudentuKon& studentai, int pasirinkimas);

#endif
