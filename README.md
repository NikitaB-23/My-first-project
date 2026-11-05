# Studentų apdorojimo programa (v1.0)

## Aprašymas
Ši programa skirta studentų duomenų apdorojimui ir spartos analizei. Ji nuskaito studentus iš failo (arba juos sugeneruoja), apskaičiuoja galutinį balą (0.4 × vidurkis + 0.6 × egzaminas), suskirsto studentus į dvi grupes (vargšiukus < 5.0 ir kietakius ≥ 5.0) ir išveda rezultatus į atskirus failus. Programoje realizuotos trys skirtingos skirstymo strategijos, leidžiančios palyginti jų spartą su `std::vector` ir `std::list` konteineriais.

## Versijų istorija (Releases)

### v.pradinė
Pirmoji versija: rankinis studentų įvedimas su namų darbų ir egzamino pažymiais, galutinio balo skaičiavimas pagal vidurkį arba medianą, įvesties validacija ir galimybė generuoti pažymius atsitiktinai.

### v0.1
Pridėtas studentų duomenų nuskaitymas iš failo (`kursiokai.txt`), rezultatų rūšiavimas ir išvedimas lentelėje, lietuviškų simbolių palaikymas Windows sistemoje.

### v0.2
Pridėtas testinių failų generavimas (1k–10M įrašų), studentų skirstymas į dvi grupes, laiko matavimas su `std::chrono` ir kelių testų vidurkis, rūšiavimas pagal naudotojo pasirinkimą. Kodas išskaidytas į atskirus `.h` ir `.cpp` failus.

### v0.3
Pridėtas `std::list` konteinerio palaikymas, `vector` ir `list` spartos palyginimas, rankinio įvedimo metu išvedamas objekto atminties adresas.

### v1.0
Pridėtos **trys skirstymo strategijos** ir jų spartos palyginimas:
1. **1 strategija (kopijavimas):** studentai kopijuojami į du naujus konteinerius, pradinis lieka nepakitęs (neefektyvu atmintiai).
2. **2 strategija (trynimas):** vargšiukai perkeliami į naują konteinerį ir ištrinami iš pradinio naudojant `erase()`.
3. **3 strategija (optimizuota):** naudojamas `std::partition` – elementai sukeičiami vietomis, nekopijuojant ir netrinant duomenų (greičiausia).

Pridėtas `CMakeLists.txt` instaliatorius, leidžiantis sukompiliuoti programą bet kokioje OS. Taip pat pridėtas bendras laiko matavimas, apimantis visus žingsnius (nuskaitymą, rūšiavimą, dalijimą ir išvedimą).

## Programos struktūra
- `main.cpp` – pagrindinis meniu.
- `Studentas.h` / `Studentas.cpp` – studento struktūra ir skaičiavimai.
- `Failai.h` / `Failai.cpp` – failų generavimas, nuskaitymas ir išvedimas.
- `Rikiavimas.h` / `Rikiavimas.cpp` – rūšiavimas.
- `Strategijos.h` / `StrategijosVector.cpp` / `StrategijosList.cpp` – 3 skirstymo strategijos.
- `Tyrimai.h` / `Tyrimai.cpp` – spartos matavimas su `std::chrono`.
- `Meniu.h` / `Meniu.cpp` – pagalbinės meniu funkcijos.
- `CMakeLists.txt` – instaliatorius.

