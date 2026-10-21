#ifndef RIKIAVIMAS_H_INCLUDED
#define RIKIAVIMAS_H_INCLUDED

#include "Studentas.h"
#include <string>

void rikiuotiStudentus(StudentuKon& studentai, const std::string& kriterijus);
void skirstytiStudentus(StudentuKon& studentai, StudentuKon& vargsai, StudentuKon& kietiakiai);

#endif
