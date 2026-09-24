#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>
#include <filesystem>

using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::vector;

struct studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double rezVid;
    double rezMed;
};

int randPaz() {
    return std::rand() % 10 + 1;
}

double skaiciuotiVidurki(const vector<int>& paz) {
    if (paz.empty()) return 0.0;
    double suma = 0;
    for (int p : paz) suma += p;
    return suma / paz.size();
}

double skaiciuotiMediana(vector<int> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    else return paz[n / 2];
}

void skaiciuotiRezultatus(studentas& s) {
    double vid = skaiciuotiVidurki(s.pazymiai);
    double med = skaiciuotiMediana(s.pazymiai);
    s.rezVid = 0.4 * vid + 0.6 * s.egzaminas;
    s.rezMed = 0.4 * med + 0.6 * s.egzaminas;
}

bool lygintiPagalPavarde(const studentas& a, const studentas& b) {
    if (a.pavarde == b.pavarde) return a.vardas < b.vardas;
    return a.pavarde < b.pavarde;
}

void valytiIvesti() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void generuotiAtsitiktiniStudenta(studentas& s) {
    string vardai[] = {"Tomas", "Lukas", "Mantas", "Rokas", "Dovydas", "Austėja", "Kamilė", "Ieva"};
    string pavardes[] = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevičius", "Vasiliauskas"};

    s.vardas = vardai[std::rand() % 8];
    s.pavarde = pavardes[std::rand() % 5];
    s.pazymiai.clear();

    int kiek = std::rand() % 5 + 3;
    for (int i = 0; i < kiek; i++) {
        s.pazymiai.push_back(randPaz());
    }
    s.egzaminas = randPaz();
    skaiciuotiRezultatus(s);
}

void nuskaitytiIsFailo(vector<studentas>& grupe, const string& failoPavadinimas) {
    cout << "Darbo katalogas: " << std::filesystem::current_path() << "\n";
    cout << "Ieskomas failas: " << std::filesystem::absolute(failoPavadinimas) << "\n";
    cout << "Failas egzistuoja: " << (std::filesystem::exists(failoPavadinimas) ? "TAIP" : "NE") << "\n";

    std::ifstream in(failoPavadinimas);
    if (!in.is_open()) {
        cout << "Nepavyko atidaryti failo!\n";
        return;
    }

    string eilute;
    std::getline(in, eilute);

    int nuskaityta = 0;
    while (std::getline(in, eilute)) {
        if (eilute.empty()) continue;
        std::istringstream ss(eilute);
        studentas s;
        if (ss >> s.vardas >> s.pavarde) {
            int p;
            while (ss >> p) s.pazymiai.push_back(p);
            if (!s.pazymiai.empty()) {
                s.egzaminas = s.pazymiai.back();
                s.pazymiai.pop_back();
                skaiciuotiRezultatus(s);
                grupe.push_back(s);
                nuskaityta++;
            }
        }
    }
    in.close();
    cout << "Sekmingai nuskaityta " << nuskaityta << " studentu is failo: " << failoPavadinimas << "\n";
}

void ivestiStudenta(studentas& s) {
    cout << "\nIveskite studento varda: "; cin >> s.vardas;
    cout << "Iveskite studento pavarde: "; cin >> s.pavarde;

    int ivestiesTipas;
    cout << "Kaip ivesti pazymius? (1 - Ranka, 2 - Generuoti atsitiktinai): ";
    while (!(cin >> ivestiesTipas) || (ivestiesTipas != 1 && ivestiesTipas != 2)) {
        valytiIvesti();
        cout << "Klaida! Iveskite 1 arba 2: ";
    }

    if (ivestiesTipas == 2) {
        int kiek;
        cout << "Kiek pazymiu sugeneruoti? ";
        while (!(cin >> kiek) || kiek <= 0) {
            valytiIvesti();
            cout << "Klaida! Iveskite teigiama skaiciu: ";
        }
        for (int i = 0; i < kiek; i++) {
            s.pazymiai.push_back(randPaz());
        }
        s.egzaminas = randPaz();
        cout << "Sugeneruotas egzamino ivertinimas: " << s.egzaminas << "\n";
    } else {
        cout << "Ivedinekite namu darbu pazymius (norėdami baigti, iveskite 0 arba neigiama skaiciu):\n";
        while (true) {
            int p;
            cout << "Pazymys: ";
            if (!(cin >> p)) {
                valytiIvesti();
                cout << "Klaida! Iveskite skaiciu.\n";
                continue;
            }
            if (p <= 0) break;
            s.pazymiai.push_back(p);
        }
        cout << "Iveskite egzamino ivertinima: ";
        while (!(cin >> s.egzaminas) || s.egzaminas < 1 || s.egzaminas > 10) {
            valytiIvesti();
            cout << "Klaida! Egzamino pazymys turi buti nuo 1 iki 10: ";
        }
    }

    skaiciuotiRezultatus(s);
}

void spausdintiRezultatus(const vector<studentas>& grupe, int pasirinkimas) {
    cout << "\n";
    cout << "|" << left << setw(15) << "Vardas" << "|" << left << setw(20) << "Pavarde";

    if (pasirinkimas == 1) cout << "|" << right << setw(18) << "Galutinis (Vid.)" << "|\n";
    else if (pasirinkimas == 2) cout << "|" << right << setw(18) << "Galutinis (Med.)" << "|\n";
    else cout << "|" << right << setw(18) << "Galutinis (Vid.)" << "|" << right << setw(18) << "Galutinis (Med.)" << "|\n";

    int ilgis = (pasirinkimas == 3) ? 73 : 54;
    cout << "|"; for (int i = 0; i < ilgis; i++) cout << "-"; cout << "|\n";

    cout << std::fixed << std::setprecision(2);
    for (const auto& st : grupe) {
        cout << "|" << left << setw(15) << st.vardas << "|" << left << setw(20) << st.pavarde;

        if (pasirinkimas == 1) cout << "|" << right << setw(18) << st.rezVid << "|\n";
        else if (pasirinkimas == 2) cout << "|" << right << setw(18) << st.rezMed << "|\n";
        else cout << "|" << right << setw(18) << st.rezVid << "|" << right << setw(18) << st.rezMed << "|\n";
    }
}

int main() {
    std::srand(std::time(0));
    vector<studentas> grupe;
    int pasirinkimas;

    while (true) {
        cout << "\n--- MENIU ---\n";
        cout << "1 - Ivesti studenta ranka / generuoti atskirai\n";
        cout << "2 - Generuoti atsitiktiniu studentu sarasa\n";
        cout << "3 - Nuskaityti studentus is failo\n";
        cout << "4 - Rodyti rezultatus lenteleje\n";
        cout << "0 - Baigti darba\n";
        cout << "Pasirinkite veiksma: ";

        if (!(cin >> pasirinkimas)) {
            valytiIvesti();
            cout << "Klaida! Iveskite skaiciu.\n";
            continue;
        }

        if (pasirinkimas == 0) break;

        if (pasirinkimas == 1) {
            char dar;
            do {
                studentas s;
                ivestiStudenta(s);
                grupe.push_back(s);
                cout << "\nAr norite ivesti dar viena studenta? (t/n): "; cin >> dar;
            } while (dar == 't' || dar == 'T');
        }
        else if (pasirinkimas == 2) {
            int kiek;
            cout << "Kiek atsitiktiniu studentu sugeneruoti? ";
            while (!(cin >> kiek) || kiek <= 0) {
                valytiIvesti();
                cout << "Klaida! Iveskite teigiama skaiciu: ";
            }
            for (int i = 0; i < kiek; i++) {
                studentas s;
                generuotiAtsitiktiniStudenta(s);
                grupe.push_back(s);
            }
            cout << "Sugeneruota " << kiek << " studentu.\n";
        }
        else if (pasirinkimas == 3) {
            string fn;
            cout << "Iveskite failo pavadinima: "; cin >> fn;
            nuskaitytiIsFailo(grupe, fn);
        }
        else if (pasirinkimas == 4) {
            if (grupe.empty()) {
                cout << "Sarasas tuscias! Is pradziu iveskite arba nuskaitykite duomenis.\n";
            } else {
                std::sort(grupe.begin(), grupe.end(), lygintiPagalPavarde);
                int isv;
                cout << "Rodyti: 1 - Vidurki, 2 - Mediana, 3 - Abu: ";
                while (!(cin >> isv) || isv < 1 || isv > 3) {
                    valytiIvesti();
                    cout << "Klaida! Iveskite 1, 2 arba 3: ";
                }
                spausdintiRezultatus(grupe, isv);
            }
        }
        else {
            cout << "Neteisingas pasirinkimas!\n";
        }
    }

    return 0;
}
