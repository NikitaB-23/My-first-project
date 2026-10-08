#include "Rikiavimas.h"
#include <algorithm>

void rikiuotiStudentus(std::vector<Studentas>& studentai,
                       const std::string& kriterijus) {
    if (kriterijus == "vardas")
        std::sort(studentai.begin(), studentai.end(), lygintiPagalVarda);
    else if (kriterijus == "pavarde")
        std::sort(studentai.begin(), studentai.end(), lygintiPagalPavarde);
    else if (kriterijus == "galutinis")
        std::sort(studentai.begin(), studentai.end(), lygintiPagalGalutini);
}

void skirstytiStudentus(std::vector<Studentas>& studentai,
                        std::vector<Studentas>& vargsai,
                        std::vector<Studentas>& kietiakiai) {
    vargsai.reserve(studentai.size() / 2);
    kietiakiai.reserve(studentai.size() / 2);

    for (auto& s : studentai) {
        if (s.rezVid < 5.0)
            vargsai.push_back(std::move(s));
        else
            kietiakiai.push_back(std::move(s));
    }
    studentai.clear();
}
