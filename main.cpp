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
    studentas s;
    cout << "Iveskite studento varda: "; cin >> s.var;
    cout << "Iveskite studento pavarde: "; cin >> s.pav;

    int p;
    cout << "Iveskite viena pazymi: "; cin >> p;
    s.paz.push_back(p);
    cout << "Iveskite egzamino ivertinima: "; cin >> s.egz;

    double vid = s.paz[0];
    double med = skaiciuotiMediana(s.paz);

    s.rezVid = 0.4 * vid + 0.6 * s.egz;
    s.rezMed = 0.4 * med + 0.6 * s.egz;

    cout << "Galutinis Vid: " << s.rezVid << " | Galutinis Med: " << s.rezMed << "\n";
    return 0;
}
