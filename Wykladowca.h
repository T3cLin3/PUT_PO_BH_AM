#pragma once
#include "Uzytkownik.h"

class Wykladowca : public Uzytkownik {
public:
    void utworzKurs();
    void dodajModul();
    void dodajLekcje();
    void wyswietlKursantow();
};