#include "Rikiavimas.h"
#include <algorithm>

void rikiuotiStudentus(StudentuKon& studentai, const std::string& kriterijus) {
    if (kriterijus == "vardas") std::sort(studentai.begin(), studentai.end(), lygintiPagalVarda);
    else if (kriterijus == "pavarde") std::sort(studentai.begin(), studentai.end(), lygintiPagalPavarde);
    else std::sort(studentai.begin(), studentai.end(), lygintiPagalGalutini);
}

void skirstytiStudentus(StudentuKon& studentai, StudentuKon& vargsai, StudentuKon& kietiakiai) {
    vargsai.reserve(studentai.size() / 2);
    kietiakiai.reserve(studentai.size() / 2);
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->rezVid < 5.0) vargsai.push_back(std::move(*it));
        else kietiakiai.push_back(std::move(*it));
        it = studentai.erase(it);
    }
}
