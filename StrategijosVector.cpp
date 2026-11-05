#include "Strategijos.h"
#include <algorithm>

void skirstyti1Vector(const std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietiakiai) {
    for (const auto& s : studentai) {
        if (s.rezVid < 5.0) vargsai.push_back(s);
        else kietiakiai.push_back(s);
    }
}

void skirstyti2Vector(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietiakiai) {
    auto it = std::partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.rezVid < 5.0;
    });
    vargsai.assign(studentai.begin(), it);
    kietiakiai.assign(it, studentai.end());
    studentai.clear();
}

void skirstyti3Vector(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietiakiai) {
    auto it = std::stable_partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.rezVid < 5.0;
    });
    vargsai.assign(studentai.begin(), it);
    kietiakiai.assign(it, studentai.end());
    studentai.clear();
}
