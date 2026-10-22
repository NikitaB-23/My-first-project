# Studentų apdorojimo programa (v0.3)

## Įvadas
Šis darbas yra objektinio programavimo kurso projektas (v0.3 versija). Pagrindinis programos tikslas – nuskaityti arba sugeneruoti studentų duomenis, apskaičiuoti jų galutinius balus (vidurkį ir medianą), suskirstyti studentus į dvi kategorijas bei atlikti std::vector ir std::list konteinerių spartos palyginimą.

## Programos struktūra
Projektas išskaidytas į kelis failus, laikantis modulinio programavimo principų ir v0.2 refactoring'o reikalavimų: 
* main.cpp – pagrindinis programos meniu ir vartotojo sąsaja. 
* Studentas.h/ Studentas.cpp– studento struktūra, galutinio balo skaičiavimo ir rūšiavimo palyginimo funkcijos. 
* Failai.h/ Failai.cpp – failų generavimas, nuskaitymas ir rezultatų išvedimas. 
* Rikiavimas.h/ Rikiavimas.cpp– studentų rūšiavimas ir skirstymas į vargšiukus ir kietakius. 
* Tyrimai.h / Tyrimai.cpp – spartos matavimai. 
* Meniu.h / Meniu.cpp– pagalbinės meniu, įvedimo ir spausdinimo funkcijos.

## Atlikti optimizavimai
Kad programa su dideliais duomenų kiekiais veiktų sparčiau, buvo atlikti šie pakeitimai:

* Buferizuotas failų rašymas: Duomenys į failą rašomi ne po vieną eilutę, o kaupiami 1 MB buferyje ir įrašomi vienu metu. Tai žymiai sumažina disko I/O operacijų skaičių.
* Atminties valdymas: Buvo pašalintas perteklinis išankstinis atminties rezervavimas (reserve) nuskaitymo metu, kuris lėtino vector konteinerį.
* Efektyvus skirstymas: Skirstant studentus į grupes,išvengiant brangaus objektų kopijavimo.

## Testavimo sistemos parametrai 
* Procesorius (CPU):Intel Core i5-1135G7 
* Operatyvioji atmintis (RAM):16 GB DDR4 
* Kietasis diskas:SSD 256GB NVMe 
* Operacinė sistema: Windows 11. 
* Kompiliatorius: GNU GCC Compiler (Code::Blocks).

## Tyrimo rezultatai 
Testavimas atliktas su anksčiau sugeneruotais failais (1000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų). Kiekvienas testas buvo pakartotas 3 kartus ir pateiktas laikų vidurkis. Šioje lentelėje pateikti rezultatai:


### 1. std::vector konteinerio rezultatai

| Studentų skaičius | Vidutinis nuskaitymo laikas | Vidutinis rūšiavimo laikas | Vidutinis dalijimo laikas | Vidutinis vargšų išvedimas | Vidutinis kietakių išvedimas | Vidutinis bendras laikas |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1000 | 0.003 | 0.000 | 0.000 | 0.000 | 0.004 | 0.007 |
| 10000 | 0.015 | 0.003 | 0.005 | 0.008 | 0.008 | 0.04 |
| 100000 | 0.191 | 0.047 | 0.005 | 0.076 | 0.109 | 0.429 |
| 1000000 | 1.911 | 0.824 | 0.07 | 1.005 | 1.237 | 5.047 |
| 10000000 | 34.518 | 12.146 | 0.959 | 11.722 | 19.441 | 78.786 |


<img width="403" height="538" alt="image" src="https://github.com/user-attachments/assets/283649c0-6d1f-4655-ace3-ad6895296ee7" />
<img width="435" height="546" alt="image" src="https://github.com/user-attachments/assets/7c65412d-7668-4b96-93ac-0db0154d42b1" />














### 2. std::list konteinerio rezultatai

| Studentų skaičius | Vidutinis nuskaitymo laikas | Vidutinis rūšiavimo laikas | Vidutinis dalijimo laikas | Vidutinis vargšų išvedimas | Vidutinis kietakių išvedimas | Vidutinis bendras laikas |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1000 | 0.007 | 0.000 | 0.000 | 0.002 | 0.002 | 0.01 |
| 10000 | 0.027 | 0.003 | 0.000 | 0.016 | 0.022 | 0.068 |
| 100000 | 0.333 | 0.047 | 0.029 | 0.180 | 0.208 | 0.798 |
| 1000000 | 3.54 | 0.543 | 0.243 | 1.522 | 2.566 | 8.414 |
| 10000000 | 41.027 | 6.674 | 2.876 | 16.493 | 22.667 | 89.737 |

 

<img width="414" height="563" alt="image" src="https://github.com/user-attachments/assets/dd71d6e7-75a4-454e-bf96-6b3351b3dc1b" />
<img width="444" height="557" alt="image" src="https://github.com/user-attachments/assets/17151c66-9d70-4740-9bd7-e071f1cf4d7b" />





     
## Išvados

`std::vector` konteineris pasirodė efektyvesnis bendram programos darbui. Su 10 000 000 įrašų visus veiksmus atliko per ~78.8 s, o `list` užtruko ~89.7 s. Skirtumas tampa akivaizdus jau apdorojant 100 000 ir daugiau įrašų.

`Vector` laimi nuskaityme, dalijime, išvedime bei bendru laiku rodant geresnį laiką. `List` laimi tik rušiavimo laike.

Bendrai `vector` pagal beveik visus rodiklius greitesnis už `list`, skirtumas ypač pastebimas su dideliais failais, todėl ir yra optimališkesnis būdas.
Project
