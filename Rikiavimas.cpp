#include "Rikiavimas.h"
#include <algorithm>
#include <list>

// Ši funkcija veiks su VECTOR 
void rikiuotiStudentus(std::vector<Studentas>& studentai, const std::string& kriterijus) {
    if (kriterijus == "vardas") std::sort(studentai.begin(), studentai.end(), lygintiPagalVarda);
    else if (kriterijus == "pavarde") std::sort(studentai.begin(), studentai.end(), lygintiPagalPavarde);
    else std::sort(studentai.begin(), studentai.end(), lygintiPagalGalutini);
}

// Ši funkcija veiks su LIST 
void rikiuotiStudentus(std::list<Studentas>& studentai, const std::string& kriterijus) {
    if (kriterijus == "vardas") studentai.sort(lygintiPagalVarda);
    else if (kriterijus == "pavarde") studentai.sort(lygintiPagalPavarde);
    else studentai.sort(lygintiPagalGalutini);
}

// Skirstymas VECTOR
void skirstytiStudentus(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietiakiai) {
    vargsai.reserve(studentai.size() / 2);
    kietiakiai.reserve(studentai.size() / 2);
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->rezVid < 5.0) vargsai.push_back(std::move(*it));
        else kietiakiai.push_back(std::move(*it));
        it = studentai.erase(it);
    }
}

void skirstytiStudentus(std::list<Studentas>& studentai, std::list<Studentas>& vargsai, std::list<Studentas>& kietiakiai) {
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->rezVid < 5.0) vargsai.push_back(std::move(*it));
        else kietiakiai.push_back(std::move(*it));
        it = studentai.erase(it);
    }
}
