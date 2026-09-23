#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

struct studentas {
    string var, pav;
    int egz;
};

int main() {
    studentas s;
    cout << "Iveskite studento varda: "; cin >> s.var;
    cout << "Iveskite studento pavarde: "; cin >> s.pav;
    cout << "Iveskite egzamino ivertinima: "; cin >> s.egz;

    cout << "\nIvestas studentas: " << s.var << " " << s.pav << " (Egzaminas: " << s.egz << ")\n";
    return 0;
}
