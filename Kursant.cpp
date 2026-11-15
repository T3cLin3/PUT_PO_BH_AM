#include "Kursant.h"
#include <iostream>

void Kursant::zapisNaKurs(std::vector<Kurs*>& listaKursow) {
    int idKursu;
    std::cout << "Podaj ID kursu, na ktory chcesz sie zapisac: ";
    std::cin >> idKursu;

    for (auto zapisany : zapisaneKursy) {
        if (zapisany->getId() == idKursu)  {
            std::cout << "Jestes juz zapisany na ten kurs.\n";
            return;
        }
    }
    for (auto kurs : listaKursow) {
        if (kurs->getId() == idKursu) {
            zapisaneKursy.push_back(kurs);
            postepy.push_back(Postep(idKursu,kurs));
            std::cout << "Pomyslnie zapisano na kurs: " << kurs->getNazwa() << std::endl;
            return;
        }
    }
    std::cout << "Nie znaleziono kursu o podanym ID.\n";
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