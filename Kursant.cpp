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

    std::cout << "Dostepne kursy na platformie:\n";
    for (auto kurs : listaKursow) {
        std::cout << "- ID: " << kurs->getId() << " | Nazwa: " << kurs->getNazwa() << std::endl;
    }
}
void Kursant::wyswietlPostepy() {
    if (zapisaneKursy.empty()) {
        std::cout << "Nie jestes zapisany na zaden kurs.\n";
        return;
    }
    std::cout << "\n--- TWOJE KURSY I POSTEPY ---\n";
    for (size_t i = 0; i < zapisaneKursy.size(); i++) {
        Kurs* k = zapisaneKursy[i];
        Postep& p = postepy[i];
        p.aktualizujPostep();
        p.sprawdzCzyOdblokowanoModul();

        std::cout << "Kurs ID: " << k->getId() << " | " << k->getNazwa()
                  << " | Postep: " << p.getProcentUkonczenia() << "%";
        if (p.sprawdzCzyOdblokowanoCertyfikat()) {
            std::cout << " [CERTYFIKAT DOSTEPNY]";
        }
        std::cout << "\n";

        for (auto& modul : k->getModuly()) {
            std::cout<< " Modul nr " << modul.getNumer() << " (ID: " << modul.getId() << ") - ";
            if (!modul.getCzyOdblokowany()) {
                std::cout << "[ZABLOKOWANY]\n";
            }
            else {
                std::cout << "[ODBLOKOWANY]\n";
                for (auto& lekcja : modul.getListaLekcji()) {
                    std::cout << "    -> Lekcja ID: " << lekcja.getId()
                              << " | Temat: " << lekcja.getTemat()
                              << " | Status: " << (lekcja.getCzyUkonczona() ? "Ukonczona" : "Nieukonczona") << "\n";
                }
            }
        }
    }
    int idKursu, idLekcji;
    std::cout << "\nPodaj ID kursu, w ktorym chcesz zrealizowac lekcje (0 - powrot): ";
    std::cin >> idKursu;
    if (idKursu == 0) return;

    for (size_t i = 0; i < zapisaneKursy.size(); i++) {
        if (zapisaneKursy[i]->getId() == idKursu) {
            std::cout << "Podaj ID lekcji do ukonczenia: ";
            std::cin >> idLekcji;

            for (auto& modul : zapisaneKursy[i]->getModuly()) {
                if (modul.getCzyOdblokowany()) {
                    for (auto& lekcja : modul.getListaLekcji()) {
                        if (lekcja.getId() == idLekcji) {
                            lekcja.oznaczJakoUkonczona();       //realizacja US 3
                            postepy[i].aktualizujPostep();      //relacja <<include>>
                            postepy[i].sprawdzCzyOdblokowanoModul();    //relacja <<extend> i US 4
                            return;
                        }
                    }
                }
            }
            std::cout << "Nie znaleziono takiej lekcji w odblokowanych modulach.\n";
            return;
        }
    }
    std::cout << "Nie jestes zapisany na kurs o podanym ID.\n";
}
void Kursant::odbierzCertyfikat() {
    if (zapisaneKursy.empty()) {
        std::cout << "Nie jestes zapisany na zaden kurs.\n";
        return;
    }

    int idKursu;
    std::cout << "Podaj ID kursu, dla ktorego chcesz odebrac certyfikat: ";
    std::cin >> idKursu;

    for (size_t i = 0; i < zapisaneKursy.size(); i++) {
        if (zapisaneKursy[i]->getId() == idKursu) {
            postepy[i].aktualizujPostep();
            if (postepy[i].sprawdzCzyOdblokowanoCertyfikat()) {
                zapisaneKursy[i]->wygenerujCertyfikat();
            } else {
                std::cout << "Nie ukonczyles jeszcze tego kursu w 100% (Twoj postep: "
                          << postepy[i].getProcentUkonczenia() << "%).\n";
            }
            return;
        }
    }

    std::cout << "Nie jestes zapisany na kurs o podanym ID.\n";
}