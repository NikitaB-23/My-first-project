#include "Tyrimai.h"
#include "Failai.h"
#include "Rikiavimas.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

using std::cin;
using std::cout;

using Clock = std::chrono::high_resolution_clock;
using Seconds = std::chrono::duration<double>;

void testuotiFailaSuVidurkiu(const std::string& failoVardas, int rikiavimas, int isvedimas, int kartai) {
    cout << "\n=== Failas " << failoVardas << " ===\n";

    double sumNuskaitymas = 0, sumRusiavimas = 0, sumSkirstymas = 0;
    double sumVargsai = 0, sumKietiakiai = 0;

    std::string kriterijus = (rikiavimas == 1) ? "vardas" : "pavarde";

    for (int k = 0; k < kartai; ++k) {
        auto t1 = Clock::now();
        StudentuKon studentai = nuskaitytiIsFailo(failoVardas);
        auto t2 = Clock::now();
        sumNuskaitymas += Seconds(t2 - t1).count();

        auto t3 = Clock::now();
        rikiuotiStudentus(studentai, kriterijus);
        auto t4 = Clock::now();
        sumRusiavimas += Seconds(t4 - t3).count();

        StudentuKon vargsai, kietiakiai;
        auto t5 = Clock::now();
        skirstytiStudentus(studentai, vargsai, kietiakiai);
        auto t6 = Clock::now();
        sumSkirstymas += Seconds(t6 - t5).count();

        auto t7 = Clock::now();
        isvestiIFaila("vargsai_" + failoVardas, vargsai, isvedimas);
        auto t8 = Clock::now();
        sumVargsai += Seconds(t8 - t7).count();

        auto t9 = Clock::now();
        isvestiIFaila("kietiakiai_" + failoVardas, kietiakiai, isvedimas);
        auto t10 = Clock::now();
        sumKietiakiai += Seconds(t10 - t9).count();
    }

    double vidViso = sumNuskaitymas + sumRusiavimas + sumSkirstymas + sumVargsai + sumKietiakiai;

    cout << std::fixed << std::setprecision(6);
    cout << "Nuskaitymo laikas: " << (sumNuskaitymas/kartai) << "\n";
    cout << "Rusiavimo laikas: " << (sumRusiavimas/kartai) << "\n";
    cout << "Dalijimo i dvi grupes laikas: " << (sumSkirstymas/kartai) << "\n";
    cout << "Vargsai isvedimas: " << (sumVargsai/kartai) << "\n";
    cout << "Kietiakiai isvedimas: " << (sumKietiakiai/kartai) << "\n";
    cout << "BENDRAS laikas: " << (vidViso/kartai) << "\n";
}

void paleistiTyrima() {
    cout << "\n=== SPARTOS TYRIMAS ===\n";
    cout << "Rikiuoti pagal: 1 - Varda, 2 - Pavarde: ";
    int rikiavimas;
    while (!(cin >> rikiavimas) || (rikiavimas != 1 && rikiavimas != 2)) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Klaida: ";
    }

    cout << "Rodyti: 1 - Vidurki, 2 - Mediana, 3 - Abu: ";
    int isvedimas;
    while (!(cin >> isvedimas) || isvedimas < 1 || isvedimas > 3) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Klaida: ";
    }

    testuotiFailaSuVidurkiu("studentai1000.txt", rikiavimas, isvedimas, 3);
    testuotiFailaSuVidurkiu("studentai10000.txt", rikiavimas, isvedimas, 3);
    testuotiFailaSuVidurkiu("studentai100000.txt", rikiavimas, isvedimas, 3);
    testuotiFailaSuVidurkiu("studentai1000000.txt", rikiavimas, isvedimas, 3);
    testuotiFailaSuVidurkiu("studentai10000000.txt", rikiavimas, isvedimas, 1);
}
