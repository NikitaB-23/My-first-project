#include "Failai.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>

using std::cout;

using Clock = std::chrono::high_resolution_clock;
using Seconds = std::chrono::duration<double>;

double generuotiFaila(const std::string& failoVardas, int n) {
    auto start = Clock::now();

    std::ofstream out(failoVardas);
    if (!out.is_open()) {
        cout << "Nepavyko sukurti: " << failoVardas << "\n";
        return 0.0;
    }

    std::mt19937 gen(42);
    std::uniform_int_distribution<int> nd(1, 10);

    for (int i = 1; i <= n; ++i) {
        out << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < 5; ++j) out << " " << nd(gen);
        out << " " << nd(gen) << "\n";
    }

    out.close();
    auto end = Clock::now();
    return Seconds(end - start).count();
}

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas) {
    std::vector<Studentas> studentai;
    std::ifstream in(failoVardas);
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti: " << failoVardas << "\n";
        return studentai;
    }

    std::string eilute;
    std::getline(in, eilute);

    studentai.reserve(1000000);

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

void isvestiIFaila(const std::string& failoVardas,
                   const std::vector<Studentas>& studentai,
                   int pasirinkimas) {
    std::ofstream out(failoVardas);
    if (!out.is_open()) {
        cout << "Nepavyko sukurti: " << failoVardas << "\n";
        return;
    }

    out << std::left << std::setw(15) << "Vardas"
        << std::left << std::setw(20) << "Pavarde";
    if (pasirinkimas == 1)
        out << std::right << std::setw(18) << "Galutinis (Vid.)";
    else if (pasirinkimas == 2)
        out << std::right << std::setw(18) << "Galutinis (Med.)";
    else
        out << std::right << std::setw(18) << "Galutinis (Vid.)"
            << std::right << std::setw(18) << "Galutinis (Med.)";
    out << "\n";

    out << std::fixed << std::setprecision(2);
    for (const auto& s : studentai) {
        out << std::left << std::setw(15) << s.vardas
            << std::left << std::setw(20) << s.pavarde;
        if (pasirinkimas == 1)
            out << std::right << std::setw(18) << s.rezVid;
        else if (pasirinkimas == 2)
            out << std::right << std::setw(18) << s.rezMed;
        else
            out << std::right << std::setw(18) << s.rezVid
                << std::right << std::setw(18) << s.rezMed;
        out << "\n";
    }
}
