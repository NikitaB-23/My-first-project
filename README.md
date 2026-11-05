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

  ## Testavimo sistemos parametrai 
* Procesorius (CPU):Intel Core i5-1135G7 
* Operatyvioji atmintis (RAM):16 GB DDR4 
* Kietasis diskas:SSD 256GB NVMe 
* Operacinė sistema: Windows 11. 
* Kompiliatorius: GNU GCC Compiler (Code::Blocks).

## Tyrimo rezultatai 
Testavimas atliktas su anksčiau sugeneruotais failais (1000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų). Kiekvienas testas buvo pakartotas 3 kartus ir pateiktas laikų vidurkis. Šioje lentelėje pateikti rezultatai:


### std::vector konteinerio rezultatai

| Studentų skaičius | Vidutinis nuskaitymo laikas | Vidutinis rūšiavimo laikas | Vidutinis dalijimo laikas(1 str.) | Vidutinis dalijimo laikas(2 str.) | Vidutinis dalijimo laikas(3 str.) | Vidutinis vargšų išvedimas | Vidutinis kietakių išvedimas | Vidutinis bendras laikas |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---|
| 1000 | 0.004 | 0.001 | 0.000 | 0.000 | 0.000 | 0.005 | 0.005 | 0.015 |
| 10000 | 0.040 | 0.004 | 0.005 | 0.002 | 0.002 | 0.016 | 0.025 | 0.087 |
| 100000 | 0.334 | 0.063 | 0.036 | 0.034 | 0.038 | 0.174 | 0.230 | 0.839 |
| 1000000 | 3.171 | 0.780 | 0.390 | 0.268 | 0.359 | 1.704 | 2.388 | 8.401 |
| 10000000 | 33.344 | 9.389 | 3.933 | 2.705 | 3.996 | 17.557 | 25.201 | 89.487 |



### std::list konteinerio rezultatai

| Studentų skaičius | Vidutinis nuskaitymo laikas | Vidutinis rūšiavimo laikas | Vidutinis dalijimo laikas(1 str.) | Vidutinis dalijimo laikas(2 str.) | Vidutinis dalijimo laikas(3 str.) | Vidutinis vargšų išvedimas | Vidutinis kietakių išvedimas | Vidutinis bendras laikas |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :---|
| 1000 | 0.004 | 0.000 | 0.001 | 0.001 | 0.001 | 0.003 | 0.002 | 0.010 |
| 10000 | 0.035 | 0.006 | 0.003 | 0.003 | 0.005 | 0.026 | 0.033 | 0.106 |
| 100000 | 0.291 | 0.084 | 0.049 | 0.040 | 0.066 | 0.202 | 0.321 | 0.963 |
| 1000000 | 3.250 | 1.340 | 0.598 | 0.584 | 0.711 | 1.750 | 2.502 | 9.553 |
| 10000000 | 32.253 | 19.093 | 5.697 | 5.507 | 8.730 | 18.371 | 25.210 | 103.658 |


## Tyrimų rezultatų išvados

1. **Nuskaitymas ir rūšiavimas:** Failo nuskaitymas abiem konteineriams užima panašiai laiko. Tačiau **rūšiavimas su `vector` yra dvigubai greitesnis** (pvz., 10M įrašų: 9.3s prieš 19.1s).

2. **Dalijimo strategijos:** 
   * **1 strategija:** `vector` žymiai greitesnis, nes kopijuoti į vientisą atmintį yra greičiau nei kurti naujus `list` elementus.
   * **2 strategija:** `list` šiek tiek laimi (2.7s prieš 3.9s ties 10M), nes ištrinti elementą iš sąrašo yra paprasčiau nei stumti visą vektorių.
   * **3 strategija:** Tai greičiausias būdas `vector` atveju, nes panaudojus `std::partition` ir `std::move` išvengiama brangaus duomenų kopijavimo.

3. **Išvedimas į failą:** Tai yra lėčiausia dalis visoje programoje (10M įrašų užtrunka 17–25s).

**Galutinė mintis:** Nors `list` turi pranašumą trinant elementus, bendrai paėmus **`std::vector` yra žymiai universalesnis ir greitesnis pasirinkimas**. Geriausias rezultatas pasiekiamas naudojant `vector` kartu su 3-čia optimizuota strategija.

<img width="493" height="463" alt="Screenshot 2026-11-04 165741" src="https://github.com/user-attachments/assets/90ba9ac6-a41c-44d6-bbe0-afbb5c353ca3" />
<img width="421" height="469" alt="Screenshot 2026-11-04 165756" src="https://github.com/user-attachments/assets/b44a0919-cd52-4819-a763-8fb587fb017b" />
<img width="424" height="317" alt="Screenshot 2026-11-04 165809" src="https://github.com/user-attachments/assets/59ed2a7c-7655-49df-a93d-e56734da12b2" />
<img width="386" height="467" alt="Screenshot 2026-11-04 165841" src="https://github.com/user-attachments/assets/8d82472b-98dd-447c-8294-6dd125c602a8" />
<img width="374" height="308" alt="Screenshot 2026-11-04 165853" src="https://github.com/user-attachments/assets/3237081b-9da2-49db-a270-a087c0808050" />



##  Įdiegimo (Instaliavimo) instrukcija

Norint sukompiliuoti ir paleisti šią programą, jums reikės:
* C++ kompiliatoriaus.
* `CMake` įrankio.

**Kompiliavimo ir paleidimo žingsniai:**

1. Atsidarykite terminalą (arba Command Prompt) programos kataloge, kur yra `CMakeLists.txt` failas.
2. Sukurkite projekto build katalogą ir sugeneruokite reikiamus failus:
   ```bash
   cmake -B build

##  Naudojimosi instrukcija

Paleidus programą, jūsų ekrane pasirodys pagrindinis meniu. Štai kaip naudotis pagrindinėmis funkcijomis:

1. **Duomenų įvedimas (1 ir 2 punktai):** Pasirinkę `1` arba `2`, galite rankiniu būdu įvesti vieną ar daugiau studentų. Programa paprašys vardo, pavardės, pažymių ir egzamino balo. Galite rinktis, ar pažymius įvesti ranka, ar juos sugeneruoti automatiškai.
2. **Studentų generavimas (3 punktas):** Pasirinkus šį punktą, programa automatiškai sugeneruos nurodytą skaičių studentų su atsitiktiniais pažymiais. Tai patogu norint greitai pamatyti, kaip veikia rikiavimas.
3. **Rezultatų peržiūra (4 punktas):** Jei jau turite įvestų studentų, šis punktas leidžia išrikiuoti juos pagal pasirinktą kriterijų (vardą, pavardę ar galutinį balą) ir išvesti gražiai suformatuotą lentelę į ekraną.
4. **Failų generavimas (5 punktas):** Programa automatiškai sukurs penkis testavimo failus (`studentai1000.txt`, `studentai10000.txt` ir t.t.) su skirtingu studentų skaičiumi. Šie failai reikalingi spartos tyrimams.
5. **Spartos tyrimai (6 ir 7 punktai):** 
   * Pasirinkus `6`, programa sugeneruos naujus failus ir iš karto atliks tyrimą.
   * Pasirinkus `7`, tyrimas bus atliekamas su jau esamais failais. 
   * Tyrimo metu programa paprašys pasirinkti konteinerį (`1` - Vector, `2` - List), rikiavimo kriterijų ir rodymo būdą. Rezultatai (laikai sekundėmis) bus išvedami į ekraną, o išskirstyti studentai bus išsaugoti naujuose `.txt` failuose.
