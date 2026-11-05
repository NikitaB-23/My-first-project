#include "Strategijos.h"
#include <algorithm>

void skirstyti1List(const std::list<Studentas>& studentai, std::list<Studentas>& vargsai, std::list<Studentas>& kietiakiai) {
    for (const auto& s : studentai) {
        if (s.rezVid < 5.0) vargsai.push_back(s);
        else kietiakiai.push_back(s);
    }
}

void skirstyti2List(std::list<Studentas>& studentai, std::list<Studentas>& vargsai, std::list<Studentas>& kietiakiai) {
    auto it = std::remove_if(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.rezVid < 5.0;
    });
    vargsai.assign(studentai.begin(), it);
    kietiakiai.assign(it, studentai.end());
    studentai.clear();
}

void skirstyti3List(std::list<Studentas>& studentai, std::list<Studentas>& vargsai, std::list<Studentas>& kietiakiai) {
    auto it = std::partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.rezVid < 5.0;
    });
    vargsai.splice(vargsai.end(), studentai, studentai.begin(), it);
    kietiakiai.splice(kietiakiai.end(), studentai);
}
