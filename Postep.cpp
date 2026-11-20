#include "Postep.h"
#include <iostream>

void Postep::aktualizujPostep() {
    int wszystkie = 0;
    int ukonczone = 0;

    for (auto& modul : kurs->getModuly()) {
        for (auto& lekcja : modul.getListaLekcji()) {
            wszystkie++;
            if (czyLekcjaUkonczona(lekcja.getId())) {
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
        if (czyModulOdblokowany(moduly[i].getId()) &&
            !czyModulOdblokowany(moduly[i+1].getId())) {
            bool wszystkieUkonczone = true;
            for (auto& lekcja : moduly[i].getListaLekcji()) {
                if (!czyLekcjaUkonczona(lekcja.getId())) {
                    wszystkieUkonczone = false;
                    break;
                }
            }
            if (wszystkieUkonczone && !moduly[i].getListaLekcji().empty()) {
                odblokowaneModuly.insert(moduly[i+1].getId());
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

void Postep::oznaczLekcjeJakoUkonczona(int idLekcji) {
    ukonczoneLekcje.insert(idLekcji);
}

bool Postep::czyLekcjaUkonczona(int idLekcji) const {
    return ukonczoneLekcje.count(idLekcji) > 0;
}

bool Postep::czyModulOdblokowany(int idModulu) const {
    return odblokowaneModuly.count(idModulu) > 0;
}