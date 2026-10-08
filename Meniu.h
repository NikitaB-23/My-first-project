#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include "Studentas.h"
#include <vector>

void ivestiStudenta(Studentas& s);

void spausdintiRezultatus(const std::vector<Studentas>& grupe, int pasirinkimas);

#endif // MENIU_H_INCLUDED
