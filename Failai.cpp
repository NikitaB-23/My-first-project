#include "Failai.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

using std::cout;

using Clock = std::chrono::high_resolution_clock;
using Seconds = std::chrono::duration<double>;

double generuotiFaila(const std::string& failoVardas, int n) {
    auto start = Clock::now();
    std::ofstream out(failoVardas);
    if (!out.is_open()) return 0.0;

    out << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas\n";

    for (int i = 1; i <= n; ++i) {
        out << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < 5; ++j) out << " " << (std::rand() % 10 + 1);
        out << " " << (std::rand() % 10 + 1) << "\n";
    }
    out.close();
    return Seconds(Clock::now() - start).count();
}

StudentuKon nuskaitytiIsFailo(const std::string& failoVardas) {
    StudentuKon studentai;
    std::ifstream in(failoVardas);
    if (!in.is_open()) return studentai;

    std::string eilute;
    if (std::getline(in, eilute)) {
        if (eilute.find("Vardas") == std::string::npos) {
            std::istringstream ss(eilute);
            Studentas s;
            if (ss >> s.vardas >> s.pavarde) {
                int p;
                while (ss >> p) s.pazymiai.push_back(p);
                if (!s.pazymiai.empty()) {
                    s.egzaminas = s.pazymiai.back();
                    s.pazymiai.pop_back();
                    skaiciuotiRezultatus(s);
                    studentai.push_back(std::move(s));
                }
            }
        }
    }

    while (std::getline(in, eilute)) {
        if (eilute.empty()) continue;
        std::istringstream ss(eilute);
        Studentas s;
        if (ss >> s.vardas >> s.pavarde) {
            int p;
            while (ss >> p) s.pazymiai.push_back(p);
            if (!s.pazymiai.empty()) {
                s.egzaminas = s.pazymiai.back();
                s.pazymiai.pop_back();
                skaiciuotiRezultatus(s);
                studentai.push_back(std::move(s));
            }
        }
    }
    return studentai;
}

void isvestiIFaila(const std::string& failoVardas, const StudentuKon& studentai, int pasirinkimas) {
    std::ofstream out(failoVardas);
    if (!out.is_open()) return;

    out << std::left << std::setw(15) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    if (pasirinkimas == 1) out << std::right << std::setw(18) << "Galutinis (Vid.)";
    else if (pasirinkimas == 2) out << std::right << std::setw(18) << "Galutinis (Med.)";
    else out << std::right << std::setw(18) << "Galutinis (Vid.)" << std::right << std::setw(18) << "Galutinis (Med.)";
    out << "\n";

    out << std::fixed << std::setprecision(2);
    for (const auto& s : studentai) {
        out << std::left << std::setw(15) << s.vardas << std::left << std::setw(20) << s.pavarde;
        if (pasirinkimas == 1) out << std::right << std::setw(18) << s.rezVid;
        else if (pasirinkimas == 2) out << std::right << std::setw(18) << s.rezMed;
        else out << std::right << std::setw(18) << s.rezVid << std::right << std::setw(18) << s.rezMed;
        out << "\n";
    }
}
