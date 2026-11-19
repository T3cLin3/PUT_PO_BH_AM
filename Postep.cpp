#include "Postep.h"
#include <iostream>

void Postep::aktualizujPostep() {
    int wszystkie = 0;
    int ukonczone = 0;

    for (auto& modul : kurs->getModuly()) {
        for (auto& lekcja : modul.getListaLekcji()) {
            wszystkie++;
            if (lekcja.getCzyUkonczona()) {
                ukonczone++;
            }
        }
    }

    if (wszystkie > 0) {
        procent_ukonczenia = (ukonczone * 100.0) /wszystkie;
    }
}

bool Postep::sprawdzCzyOdblokowanoModul() {
    auto& moduly = kurs->getModuly();
    for (size_t i = 0; i +1 < moduly.size();i++) {
        if (moduly[i].getCzyOdblokowany() && !moduly[i+1].getCzyOdblokowany()) {
            bool wszystkieUkonczone = true;
            for (auto& lekcja : moduly[i].getListaLekcji()) {
                if (!lekcja.getCzyUkonczona()) {
                    wszystkieUkonczone = false;
                    break;
                }
            }
            if (wszystkieUkonczone && !moduly[i].getListaLekcji().empty()) {
                moduly[i+1].setCzyOdblokowany(true);
                std::cout << "Odblokowano kolejny modul (nr " << moduly[i+1].getNumer() << ")!" << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool Postep::sprawdzCzyOdblokowanoCertyfikat() {
    return procent_ukonczenia >= 100.0;
}