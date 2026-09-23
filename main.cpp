#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

bool lygintiPagalPavarde(const studentas& a, const studentas& b) {
    if (a.pavarde == b.pavarde) return a.vardas < b.vardas;
    return a.pavarde < b.pavarde;
}

int main() {
    std::srand(std::time(0));
    vector<studentas> grupe;

    while (true) {
        studentas s;
        cout << "\nIveskite studento varda: "; cin >> s.vardas;
        cout << "Iveskite studento pavarde: "; cin >> s.pavarde;

        int ivestiesTipas;
        cout << "Kaip ivesti pazymius? (1 - Ranka, 2 - Generuoti atsitiktinai): ";
        cin >> ivestiesTipas;

        if (ivestiesTipas == 2) {
            int kiek;
            cout << "Kiek pazymiu sugeneruoti? "; cin >> kiek;
            for (int i = 0; i < kiek; i++) {
                s.pazymiai.push_back(std::rand() % 10 + 1);
            }
            s.egzaminas = std::rand() % 10 + 1;
            cout << "Sugeneruotas egzamino ivertinimas: " << s.egzaminas << "\n";
        } else {
            cout << "Ivedinekite namu darbu pazymius (norėdami baigti, iveskite 0 arba neigiama skaiciu):\n";
            while (true) {
                int p;
                cout << "Pazymys: "; cin >> p;
                if (p <= 0) break;
                s.pazymiai.push_back(p);
            }
            cout << "Iveskite egzamino ivertinima: "; cin >> s.egzaminas;
        }

        double vid = skaiciuotiVidurki(s.pazymiai);
        double med = skaiciuotiMediana(s.pazymiai);

        s.rezVid = 0.4 * vid + 0.6 * s.egzaminas;
        s.rezMed = 0.4 * med + 0.6 * s.egzaminas;

        grupe.push_back(s);

        char dar;
        cout << "\n Ar norite ivesti dar viena studenta? (t/n): "; cin >> dar;
        if (dar == 'n' || dar == 'N') break;
    }

    if (grupe.empty()) return 0;

    std::sort(grupe.begin(), grupe.end(), lygintiPagalPavarde);

    int pasirinkimas;
    cout << "\nPasirinkite isvedima (1 - Vidurkis, 2 - Mediana, 3 - Abu): ";
    cin >> pasirinkimas;

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

    return 0;
}
