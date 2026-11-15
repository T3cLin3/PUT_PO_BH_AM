#include "Wykladowca.h"
#include <iostream>

void Wykladowca::utworzKurs(std::vector<Kurs*>& listaKursow) {
    int idKursu;
    std::string nazwaKursu;

    std::cout << "Podaj ID nowego kursu: ";
    std::cin >> idKursu;
    std::cout << "Podaj  nazwe kursu: ";
    std::getline(std::cin >> std::ws,nazwaKursu);

    Kurs* nowyKurs = new Kurs(idKursu,nazwaKursu);
    listaKursow.push_back(nowyKurs);
    std::cout << "Pomyślnie utworzono kurs: " << nazwaKursu << std::endl;
}
void Wykladowca::dodajModul() {}
void Wykladowca::dodajLekcje() {}
void Wykladowca::wyswietlKursantow() {}