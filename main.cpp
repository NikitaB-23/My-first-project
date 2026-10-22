#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Studentas.h"
#include "Failai.h"
#include "Rikiavimas.h"
#include "Tyrimai.h"
#include "Meniu.h"

using namespace std;

int main() {
    srand(time(0));
    StudentuKon grupe;
    int pas;
    while (true) {
        cout << "\nMENIU:\n";
        cout << "1 - Ivesti studenta ranka\n";
        cout << "2 - Generuoti studentu sarasa\n";
        cout << "3 - Rodyti studentus lenteleje\n";
        cout << "4 - Sugeneruoti 5 testinius failus\n";
        cout << "5 - Tyrimas su NAUJAI sugeneruotais failais\n";
        cout << "6 - Tyrimas su JAU TURIMAIS failais\n";
        cout << "0 - Baigti darba\n";
        cout << "Pasirinkite: ";

        if (!(cin >> pas)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        if (pas == 0) break;

        if (pas == 1) {
            char dar;
            do {
                Studentas s;
                ivestiStudenta(s);
                grupe.push_back(s);
                cout << "Studento atminties adresas: " << &grupe.back() << "\n";
                cout << "Ar dar viena? (t/n): "; cin >> dar;
            } while (dar == 't' || dar == 'T');
        }
        else if (pas == 2) {
            int kiek;
            cout << "Kiek studentu? ";
            while (!(cin >> kiek) || kiek <= 0) { cin.clear(); cin.ignore(10000, '\n'); }
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
        else if (pas == 3) {
            if (grupe.empty()) {
                cout << "Sarasas tuscias! Pirma ikelkite duomenis.\n";
            } else {
                int isv, r, tv;
                cout << "Rodyti: 1 - Vidurki, 2 - Mediana, 3 - Abu: ";
                while (!(cin >> isv) || isv < 1 || isv > 3) { cin.clear(); cin.ignore(10000, '\n'); }
                cout << "Rikiuoti pagal: 1 - Varda, 2 - Pavarde: ";
                while (!(cin >> r) || (r != 1 && r != 2)) { cin.clear(); cin.ignore(10000, '\n'); }
                cout << "Tvarka: 1 - Didejimo, 2 - Mazejimo: ";
                while (!(cin >> tv) || (tv != 1 && tv != 2)) { cin.clear(); cin.ignore(10000, '\n'); }
                string krit = (r == 1) ? "vardas" : "pavarde";
                Tvarka t = (tv == 1) ? Tvarka::Didejimo : Tvarka::Mazejimo;
                rikiuotiStudentus(grupe, krit, t);
                spausdintiRezultatus(grupe, isv);
            }
        }
        else if (pas == 4) {
            generuotiFaila("studentai1000.txt", 1000);
            generuotiFaila("studentai10000.txt", 10000);
            generuotiFaila("studentai100000.txt", 100000);
            generuotiFaila("studentai1000000.txt", 1000000);
            generuotiFaila("studentai10000000.txt", 10000000);
            cout << "Sugeneruota!\n";
        }
        else if (pas == 5) {
            paleistiTyrima(true);
        }
        else if (pas == 6) {
            paleistiTyrima(false);
        }
    }
    return 0;
}
