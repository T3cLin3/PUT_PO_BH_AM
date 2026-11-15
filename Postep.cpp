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
    return false;
}

bool Postep::sprawdzCzyOdblokowanoCertyfikat() {
    return procent_ukonczenia >= 100.0;
}