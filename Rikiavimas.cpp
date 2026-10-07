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

static void strategijaEigeris(std::vector<Studentas>& studentai,
                              std::vector<Studentas>& vargsai,
                              std::vector<Studentas>& kietiakiai) {
    std::stable_partition(studentai.begin(), studentai.end(),
        [](const Studentas& s){ return s.rezVid < 5.0; });

    auto it = std::find_if(studentai.begin(), studentai.end(),
        [](const Studentas& s){ return s.rezVid >= 5.0; });

    vargsai.assign(studentai.begin(), it);
    kietiakiai.assign(it, studentai.end());
    studentai.clear();
}

static void strategijaDvieju(std::vector<Studentas>& studentai,
                             std::vector<Studentas>& vargsai,
                             std::vector<Studentas>& kietiakiai) {
    vargsai.reserve(studentai.size() / 2);
    kietiakiai.reserve(studentai.size() / 2);

    for (const auto& s : studentai) {
        if (s.rezVid < 5.0) vargsai.push_back(s);
        else                kietiakiai.push_back(s);
    }
    studentai.clear();
}

static void strategijaOptimali(std::vector<Studentas>& studentai,
                               std::vector<Studentas>& vargsai,
                               std::vector<Studentas>& kietiakiai) {
    std::vector<Studentas> like;
    like.reserve(studentai.size() / 2);
    vargsai.reserve(studentai.size() / 2);

    for (auto& s : studentai) {
        if (s.rezVid < 5.0) vargsai.push_back(std::move(s));
        else                like.push_back(std::move(s));
    }
    studentai.clear();
    kietiakiai = std::move(like);
}

void skirstytiStudentus(std::vector<Studentas>& studentai,
                        std::vector<Studentas>& vargsai,
                        std::vector<Studentas>& kietiakiai,
                        Strategija strategija) {
    switch (strategija) {
        case Strategija::EIGERIS:  strategijaEigeris (studentai, vargsai, kietiakiai); break;
        case Strategija::DVIEJU:   strategijaDvieju  (studentai, vargsai, kietiakiai); break;
        case Strategija::OPTIMALI: strategijaOptimali(studentai, vargsai, kietiakiai); break;
    }
}
