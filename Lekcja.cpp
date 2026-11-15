#include "Lekcja.h"
#include <iostream>

void Lekcja::oznaczJakoUkonczona() {
    czy_ukonczona = true;
    std::cout << "Lekcja [" << temat<< "] zostala ukonczona!" << std::endl;
}