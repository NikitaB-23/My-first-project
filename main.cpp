#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Studentas.h"
#include "Failai.h"
#include "Rikiavimas.h"
#include "Tyrimai.h"
#include "Meniu.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main() {
    std::srand(std::time(0));
    vector<Studentas> grupe;
    int pasirinkimas;

    while (true) {
        cout << "\n--- MENIU ---\n";
        cout << "1 - Ivesti studenta ranka\n";
        cout << "2 - Generuoti studentu sarasa\n";
        cout << "3 - Nuskaityti studentus is failo\n";
        cout << "4 - Rodyti rezultatus lenteleje\n";
        cout << "5 - Sugeneruoti 5 testinius failus\n";
        cout << "6 - Paleisti spartos tyrima\n";
        cout << "0 - Baigti darba\n";
        cout << "Pasirinkite: ";

        if (!(cin >> pasirinkimas)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (pasirinkimas == 0) break;

        if (pasirinkimas == 1) {
            char dar;
            do {
                Studentas s;
                ivestiStudenta(s);
                grupe.push_back(s);
                cout << "Ar dar viena? (t/n): "; cin >> dar;
            } while (dar == 't' || dar == 'T');
        }
        else if (pasirinkimas == 2) {
            int kiek;
            cout << "Kiek studentu? ";
            while (!(cin >> kiek) || kiek <= 0) {
                cin.clear(); cin.ignore(10000, '\n');
                cout << "Klaida: ";
            }
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                s.vardas = "Vardas" + std::to_string(i + 1);
                s.pavarde = "Pavarde" + std::to_string(i + 1);
                for (int j = 0; j < 5; j++) s.pazymiai.push_back(randPaz());
                s.egzaminas = randPaz();
                skaiciuotiRezultatus(s);
                grupe.push_back(s);
            }
            cout << "Sugeneruota " << kiek << " studentu.\n";
        }
        else if (pasirinkimas == 3) {
            string fn;
            cout << "Failo pavadinimas: "; cin >> fn;
            auto nuskaityti = nuskaitytiIsFailo(fn);
            grupe.insert(grupe.end(), nuskaityti.begin(), nuskaityti.end());
        }
        else if (pasirinkimas == 4) {
            if (grupe.empty()) {
                cout << "Sarasas tuscias!\n";
            } else {
                int isv;
                cout << "Rodyti: 1 - Vidurki, 2 - Mediana, 3 - Abu: ";
                while (!(cin >> isv) || isv < 1 || isv > 3) {
                    cin.clear(); cin.ignore(10000, '\n');
                    cout << "Klaida! 1, 2 arba 3: ";
                }
                int rik;
                cout << "Rikiuoti pagal: 1 - Varda, 2 - Pavarde: ";
                while (!(cin >> rik) || (rik != 1 && rik != 2)) {
                    cin.clear(); cin.ignore(10000, '\n');
                    cout << "Klaida! 1 arba 2: ";
                }
                if (rik == 1) rikiuotiStudentus(grupe, "vardas");
                else          rikiuotiStudentus(grupe, "pavarde");
                spausdintiRezultatus(grupe, isv);
            }
        }
        else if (pasirinkimas == 5) {
            std::vector<std::pair<string,int>> failai = {
                {"studentai1000.txt",       1000},
                {"studentai10000.txt",      10000},
                {"studentai100000.txt",     100000},
                {"studentai1000000.txt",    1000000},
                {"studentai10000000.txt",   10000000}
            };
            for (auto& pora : failai) {
                double laikas = generuotiFaila(pora.first, pora.second);
                cout << pora.first << " (" << pora.second << " irasu): "
                     << laikas << " s\n";
            }
        }
        else if (pasirinkimas == 6) {
            paleistiTyrima();
        }
    }

    return 0;
}
