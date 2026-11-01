#pragma once
#include <vector>
#include "Lekcja.h"

class Modul {
private:
    int id;
    int numer;
    bool czy_odblokowany;
    std::vector<Lekcja> listaLekcji;
};