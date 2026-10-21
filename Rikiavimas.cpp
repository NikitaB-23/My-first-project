#include "Rikiavimas.h"
#include <algorithm>
#include <type_traits>
#include <list>

void rikiuotiStudentus(StudentuKon& studentai, const std::string& kriterijus) {
    if constexpr (std::is_same_v<StudentuKon, std::list<Studentas>>) {
        if (kriterijus == "vardas") studentai.sort(lygintiPagalVarda);
        else if (kriterijus == "pavarde") studentai.sort(lygintiPagalPavarde);
        else if (kriterijus == "galutinis") studentai.sort(lygintiPagalGalutini);
    } else {
        if (kriterijus == "vardas") std::sort(studentai.begin(), studentai.end(), lygintiPagalVarda);
        else if (kriterijus == "pavarde") std::sort(studentai.begin(), studentai.end(), lygintiPagalPavarde);
        else if (kriterijus == "galutinis") std::sort(studentai.begin(), studentai.end(), lygintiPagalGalutini);
    }
}

void skirstytiStudentus(StudentuKon& studentai, StudentuKon& vargsai, StudentuKon& kietiakiai) {
    if constexpr (std::is_same_v<StudentuKon, std::vector<Studentas>>) {
        vargsai.reserve(studentai.size() / 2);
        kietiakiai.reserve(studentai.size() / 2);
    }

    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->rezVid < 5.0) vargsai.push_back(std::move(*it));
        else kietiakiai.push_back(std::move(*it));
        it = studentai.erase(it);
    }
}
