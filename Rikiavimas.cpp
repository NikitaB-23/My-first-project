#include "Rikiavimas.h"
#include <algorithm>
#include <list>

void rikiuotiStudentus(StudentuKon& studentai, const std::string& kriterijus, Tvarka tvarka) {
    auto cmp = [kriterijus, tvarka](const Studentas& a, const Studentas& b) {
        if (kriterijus == "vardas") return tvarka == Tvarka::Didejimo ? a.vardas < b.vardas : a.vardas > b.vardas;
        if (kriterijus == "pavarde") return tvarka == Tvarka::Didejimo ? a.pavarde < b.pavarde : a.pavarde > b.pavarde;
        return tvarka == Tvarka::Didejimo ? a.rezVid < b.rezVid : a.rezVid > b.rezVid;
    };

    std::sort(studentai.begin(), studentai.end(), cmp);
    //studentai.sort(cmp);
}

void skirstytiStudentus(StudentuKon& studentai, StudentuKon& vargsai, StudentuKon& kietiakiai) {

    vargsai.reserve(studentai.size() / 2);
   kietiakiai.reserve(studentai.size() / 2);

    for (auto& s : studentai) {
        if (s.rezVid < 5.0) vargsai.push_back(std::move(s));
        else kietiakiai.push_back(std::move(s));
    }
}
