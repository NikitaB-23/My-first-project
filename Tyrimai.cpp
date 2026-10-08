#include "Tyrimai.h"
#include "Failai.h"
#include "Rikiavimas.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>

using std::cin;
using std::cout;

using Clock = std::chrono::high_resolution_clock;
using Seconds = std::chrono::duration<double>;

void testuotiFailaSuVidurkiu(const std::string& failoVardas,
                              Strategija strategija,
                              int rikiavimas,
                              int isvedimas,
                              int kartai) {
    cout << "\n=== Failas " << failoVardas
         << " (vidurkis is " << kartai << " testu) ===\n";

    double sumNuskaitymas = 0, sumRusiavimas = 0, sumSkirstymas = 0;
    double sumVargsai = 0, sumKietiakiai = 0;
    std::size_t vargsaiSk = 0, kietiakiaiSk = 0;

    std::string kriterijus = (rikiavimas == 1) ? "vardas" : "pavarde";

    for (int k = 0; k < kartai; ++k) {
        auto t1 = Clock::now();
        auto studentai = nuskaitytiIsFailo(failoVardas);
        auto t2 = Clock::now();
        sumNuskaitymas += Seconds(t2 - t1).count();

        auto t3 = Clock::now();
        rikiuotiStudentus(studentai, kriterijus);
        auto t4 = Clock::now();
        sumRusiavimas += Seconds(t4 - t3).count();

        std::vector<Studentas> vargsai, kietiakiai;
        auto t5 = Clock::now();
        skirstytiStudentus(studentai, vargsai, kietiakiai, strategija);
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

        vargsaiSk = vargsai.size();
        kietiakiaiSk = kietiakiai.size();
    }

    double vidNuskaitymas = sumNuskaitymas / kartai;
    double vidRusiavimas  = sumRusiavimas  / kartai;
    double vidSkirstymas  = sumSkirstymas  / kartai;
    double vidVargsai     = sumVargsai     / kartai;
    double vidKietiakiai  = sumKietiakiai  / kartai;
    double vidViso = vidNuskaitymas + vidRusiavimas + vidSkirstymas
                   + vidVargsai + vidKietiakiai;

    cout << std::fixed << std::setprecision(6);
    cout << "Nuskaitymo laikas: " << vidNuskaitymas << "\n";
    cout << "Rusiavimo laikas (pagal " << kriterijus << "): " << vidRusiavimas << "\n";
    cout << "Dalijimo i dvi grupes laikas: " << vidSkirstymas << "\n";
    cout << "Vargsai isvedimas i faila: " << vidVargsai << "\n";
    cout << "Kietiakiai isvedimas i faila: " << vidKietiakiai << "\n";
    cout << "BENDRAS laikas: " << vidViso << "\n";
    cout << "Vargsai: " << vargsaiSk
         << ", Kietiakiai: " << kietiakiaiSk << "\n";
}

void paleistiTyrima() {
    cout << "\n=== SPARTOS TYRIMAS ===\n";
    cout << "Rikiuoti pagal: 1 - Varda, 2 - Pavarde: ";
    int rikiavimas;
    while (!(cin >> rikiavimas) || (rikiavimas != 1 && rikiavimas != 2)) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Klaida! 1 arba 2: ";
    }

    cout << "Rodyti: 1 - Vidurki, 2 - Mediana, 3 - Abu: ";
    int isvedimas;
    while (!(cin >> isvedimas) || isvedimas < 1 || isvedimas > 3) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Klaida! 1, 2 arba 3: ";
    }

    std::vector<std::string> failai = {
        "studentai1000.txt",
        "studentai10000.txt",
        "studentai100000.txt",
        "studentai1000000.txt"
    };

    for (const auto& f : failai)
        testuotiFailaSuVidurkiu(f, Strategija::OPTIMALI, rikiavimas, isvedimas, 3);
}
