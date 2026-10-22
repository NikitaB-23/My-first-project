#include "Meniu.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void ivestiStudenta(Studentas& s) {
    cout << "\nVardas: "; cin >> s.vardas; cout << "Pavarde: "; cin >> s.pavarde;
    int k, t; cout << "1-Ranka, 2-Generuoti: "; cin >> t;
    if (t == 2) { cout << "Kiek? "; cin >> k; for(int i=0; i<k; i++) s.pazymiai.push_back(randPaz()); s.egzaminas = randPaz(); }
    else { int p; cout << "Pazymiai (0-baigti):\n"; while(cin >> p && p>0) s.pazymiai.push_back(p); cout << "Egz: "; cin >> s.egzaminas; }
    skaiciuotiRezultatus(s); cout << "Adresas: " << &s << "\n";
}

void spausdintiRezultatus(const StudentuKon& g, int pas) {
    cout << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << right << setw(15) << "Galutinis" << "\n";
    for (const auto& s : g) cout << left << setw(15) << s.vardas << setw(20) << s.pavarde << right << setw(15) << fixed << setprecision(2) << (pas == 1 ? s.rezVid : s.rezMed) << "\n";
}
