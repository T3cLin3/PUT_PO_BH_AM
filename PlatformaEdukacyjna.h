#pragma once
#include <vector>
#include "Kursant.h"
#include "Wykladowca.h"
#include "Kurs.h"

class PlatformaEdukacyjna {
private:
    std::vector<Kursant*> listaKursantow;
    std::vector<Wykladowca*> listaWykladowcow;
    std::vector<Kurs*> listaKursow;
public:
    void zarzadzanieUzytkownikami();
};