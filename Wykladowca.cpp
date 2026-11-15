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
void Wykladowca::dodajModul(std::vector<Kurs*>&listaKursow) {
    int idKursu , idModulu, numerModulu;
    std::cout << "Podaj ID kursu, do ktorego chcesz dodac modul: ";
    std::cin >> idKursu;

    for (auto kurs : listaKursow) {
        if (kurs->getId() == idKursu) {
            std::cout << "Podaj ID nowego modulu: ";
            std::cin >> idModulu;
            std::cout << "Podaj numer kolejny modulu: ";
            std::cin >> numerModulu;

            bool odblokowany = kurs->getModuly().empty();
            kurs->dodajModul(Modul(idModulu, numerModulu , odblokowany));
            std::cout << "Dodano modul nr " << numerModulu << " do kursu " <<kurs->getNazwa() << std::endl;
            return;
        }
    }
    std::cout << "Nie znaleziono kursu o podanym ID. \n";
}
void Wykladowca::dodajLekcje(std::vector<Kurs*>& listaKursow) {
    int idKursu, idModulu , idLekcji;
    std::string tematLekcji;

    std::cout << "Podaj ID kursu: ";
    std::cin >> idKursu;

    for (auto kurs: listaKursow) {
        if (kurs->getId() == idKursu) {
            std::cout << "Podaj ID modulu: ";
            std::cin >> idModulu;

            for (auto& modul : kurs->getModuly()) {
                if (modul.getId() == idModulu) {
                    std::cout << "Podaj ID nowej lekcji: ";
                    std::cin  >> idLekcji;
                    std::cout << "Podaj temat lekcji: ";
                    std::getline(std::cin >> std::ws, tematLekcji);

                    modul.dodajLekcje(Lekcja(idLekcji,tematLekcji));
                    std::cout << "Dodano lekcje [" << tematLekcji << "] do modulu nr " << modul.getNumer() <<std::endl;
                    return;
                }
            }
            std::cout << "Nie znaleziono modulu o podanym ID \n";
            return;
        }
    }
    std::cout << "Nie znaleziono kursu o podanym ID \n";
}
void Wykladowca::wyswietlKursantow() {}