#include "Kursant.h"
#include <iostream>

void Kursant::zapisNaKurs() {
    std::cout << "Kursant zapisuje sie na kurs." << std::endl;
}
void Kursant::wyswietlDostepneKursy(std::vector<Kurs*>& listaKursow) {
    if (listaKursow.empty()) {
        std::cout << "Brak dostepnych kursow na platformie. \n";
        return;
    }

    std::cout << "Dostępne kursy na platformie:\n";
    for (auto kurs : listaKursow) {
        std::cout << "- ID: " << kurs->getId() << " | Nazwa: " << kurs->getNazwa() << std::endl;
    }
}
void Kursant::wyswietlPostepy() {}
void Kursant::odbierzCertyfikat() {}