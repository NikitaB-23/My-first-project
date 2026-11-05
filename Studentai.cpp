#include "Studentas.h"
#include <algorithm>
#include <cstdlib>

int randPaz() { return std::rand() % 10 + 1; }

double skaiciuotiVidurki(const std::vector<int>& paz) {
    if (paz.empty()) return 0.0;
    double suma = 0; for (int p : paz) suma += p; return suma / paz.size();
}

double skaiciuotiMediana(std::vector<int> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    return paz[n / 2];
}

void skaiciuotiRezultatus(Studentas& s) {
    s.vidurkis = skaiciuotiVidurki(s.pazymiai);
    s.mediana = skaiciuotiMediana(s.pazymiai);
    s.rezVid = 0.4 * s.vidurkis + 0.6 * s.egzaminas;
    s.rezMed = 0.4 * s.mediana + 0.6 * s.egzaminas;
}
