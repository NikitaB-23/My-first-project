#include "Failai.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <iostream>

using std::cout;
using Clock = std::chrono::high_resolution_clock;
using Seconds = std::chrono::duration<double>;

double generuotiFaila(const std::string& fn, int n) {
    auto start = Clock::now();
    std::ofstream out(fn);
    if (!out.is_open()) return 0.0;

    out << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas\n";

    std::string buffer;
    buffer.reserve(1024 * 1024);

    for (int i = 1; i <= n; ++i) {
        buffer += "Vardas" + std::to_string(i) + " Pavarde" + std::to_string(i);
        for (int j = 0; j < 5; ++j) buffer += " " + std::to_string(std::rand() % 10 + 1);
        buffer += " " + std::to_string(std::rand() % 10 + 1) + "\n";

        if (buffer.size() >= 1024 * 1024) {
            out << buffer;
            buffer.clear();
        }
    }
    if (!buffer.empty()) out << buffer;

    return Seconds(Clock::now() - start).count();
}

StudentuKon nuskaitytiIsFailo(const std::string& fn) {
    StudentuKon studentai;
    std::ifstream in(fn);
    if (!in.is_open()) return studentai;

    std::string eilute;
    std::getline(in, eilute);

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

void isvestiIFaila(const std::string& fn, const StudentuKon& studentai, int pas) {
    std::ofstream out(fn);
    if (!out.is_open()) return;

    out << std::left << std::setw(15) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    if (pas == 1) out << std::right << std::setw(18) << "Galutinis (Vid.)";
    else if (pas == 2) out << std::right << std::setw(18) << "Galutinis (Med.)";
    else out << std::right << std::setw(18) << "Galutinis (Vid.)" << std::right << std::setw(18) << "Galutinis (Med.)";
    out << "\n" << std::fixed << std::setprecision(2);

    std::string buffer;
    buffer.reserve(1024 * 1024);

    for (const auto& s : studentai) {
        std::ostringstream ss;
        ss << std::left << std::setw(15) << s.vardas << std::left << std::setw(20) << s.pavarde;
        if (pas == 1) ss << std::right << std::setw(18) << s.rezVid;
        else if (pas == 2) ss << std::right << std::setw(18) << s.rezMed;
        else ss << std::right << std::setw(18) << s.rezVid << std::right << std::setw(18) << s.rezMed;
        ss << "\n";

        buffer += ss.str();
        if (buffer.size() >= 1024 * 1024) {
            out << buffer;
            buffer.clear();
        }
    }
    if (!buffer.empty()) out << buffer;
}
