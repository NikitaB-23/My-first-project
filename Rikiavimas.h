#ifndef RIKIAVIMAS_H_INCLUDED
#define RIKIAVIMAS_H_INCLUDED

#include "Studentas.h"
#include <string>
#include <vector>
#include <list>

void rikiuotiStudentus(std::vector<Studentas>& studentai, const std::string& kriterijus);
void rikiuotiStudentus(std::list<Studentas>& studentai, const std::string& kriterijus);

void skirstytiStudentus(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietiakiai);
void skirstytiStudentus(std::list<Studentas>& studentai, std::list<Studentas>& vargsai, std::list<Studentas>& kietiakiai);

#endif
