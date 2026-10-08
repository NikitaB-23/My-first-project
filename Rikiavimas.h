#ifndef RIKIAVIMAS_H_INCLUDED
#define RIKIAVIMAS_H_INCLUDED

#include "Studentas.h"
#include <string>
#include <vector>

void rikiuotiStudentus(std::vector<Studentas>& studentai,
                       const std::string& kriterijus);

void skirstytiStudentus(std::vector<Studentas>& studentai,
                        std::vector<Studentas>& vargsai,
                        std::vector<Studentas>& kietiakiai);

#endif // RIKIAVIMAS_H_INCLUDED
