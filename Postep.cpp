#include "Postep.h"
#include <iostream>

void Postep::aktualizujPostep() {
    std::cout << "Postep zostal zaktualizowany." << std::endl;
}

bool Postep::sprawdzCzyOdblokowanoModul() {
    return false;
}

bool Postep::sprawdzCzyOdblokowanoCertyfikat() {
    return false;
}