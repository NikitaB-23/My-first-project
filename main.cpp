#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;

struct studentas {
    string var, pav;
    vector<int> paz;
    int egz;
    double rezVid;
    double rezMed;
};

double skaiciuotiMediana(vector<int> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    else return paz[n / 2];
}

int main() {
    vector<studentas> grupe;

    while (true) {
        studentas s;
        cout << "\nIveskite studento varda: "; cin >> s.var;
        cout << "Iveskite studento pavarde: "; cin >> s.pav;

        cout << "Ivedinekite pazymius (0 - baigti):\n";
        while (true) {
            int p;
            cout << "Pazymys: "; cin >> p;
            if (p <= 0) break;
            s.paz.push_back(p);
        }
        cout << "Iveskite egzamino ivertinima: "; cin >> s.egz;

        double suma = 0;
        for (int p : s.paz) suma += p;
        double vid = s.paz.empty() ? 0.0 : suma / s.paz.size();
        double med = skaiciuotiMediana(s.paz);

        s.rezVid = 0.4 * vid + 0.6 * s.egz;
        s.rezMed = 0.4 * med + 0.6 * s.egz;

        grupe.push_back(s);

        char dar;
        cout << "Ar norite ivesti dar viena studenta? (t/n): "; cin >> dar;
        if (dar == 'n' || dar == 'N') break;
    }

    return 0;
}
