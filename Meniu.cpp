#include "Meniu.h"
#include <iostream>
#include <iomanip>
#include <limits>

using std::cin;
using std::cout;

void ivestiStudenta(Studentas& s) {
    cout << "\nIveskite studento varda: "; cin >> s.vardas;
    cout << "Iveskite studento pavarde: "; cin >> s.pavarde;

    int tipas;
    cout << "Kaip ivesti pazymius? (1 - Ranka, 2 - Generuoti): ";
    while (!(cin >> tipas) || (tipas != 1 && tipas != 2)) {
        cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Klaida! Iveskite 1 arba 2: ";
    }

    if (tipas == 2) {
        int kiek;
        cout << "Kiek pazymiu? ";
        while (!(cin >> kiek) || kiek <= 0) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Klaida: ";
        }
        for (int i = 0; i < kiek; i++) s.pazymiai.push_back(randPaz());
        s.egzaminas = randPaz();
        cout << "Sugeneruotas egzaminas: " << s.egzaminas << "\n";
    } else {
        cout << "Pazymiai (0 - baigti):\n";
        while (true) {
            int p; cout << "Pazymys: ";
            if (!(cin >> p)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
            if (p <= 0) break;
            s.pazymiai.push_back(p);
        }
        cout << "Egzamino ivertinimas: ";
        while (!(cin >> s.egzaminas) || s.egzaminas < 1 || s.egzaminas > 10) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Klaida! 1-10: ";
        }
    }
    skaiciuotiRezultatus(s);
}

void spausdintiRezultatus(const std::vector<Studentas>& grupe, int pasirinkimas) {
    cout << "\n";
    cout << "|" << std::left << std::setw(15) << "Vardas"
         << "|" << std::left << std::setw(20) << "Pavarde";

    if (pasirinkimas == 1)
        cout << "|" << std::right << std::setw(18) << "Galutinis (Vid.)" << "|\n";
    else if (pasirinkimas == 2)
        cout << "|" << std::right << std::setw(18) << "Galutinis (Med.)" << "|\n";
    else
        cout << "|" << std::right << std::setw(18) << "Galutinis (Vid.)"
             << "|" << std::right << std::setw(18) << "Galutinis (Med.)" << "|\n";

    int ilgis = (pasirinkimas == 3) ? 73 : 54;
    cout << "|"; for (int i = 0; i < ilgis; i++) cout << "-"; cout << "|\n";

    cout << std::fixed << std::setprecision(2);
    for (const auto& s : grupe) {
        cout << "|" << std::left << std::setw(15) << s.vardas
             << "|" << std::left << std::setw(20) << s.pavarde;
        if (pasirinkimas == 1)
            cout << "|" << std::right << std::setw(18) << s.rezVid << "|\n";
        else if (pasirinkimas == 2)
            cout << "|" << std::right << std::setw(18) << s.rezMed << "|\n";
        else
            cout << "|" << std::right << std::setw(18) << s.rezVid
                 << "|" << std::right << std::setw(18) << s.rezMed << "|\n";
    }
}
