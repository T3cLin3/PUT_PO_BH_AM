#pragma once
#include "Uzytkownik.h"

class Wykladowca : public Uzytkownik {
public:
    Wykladowca(int id_w, std::string i, std::string n) {
        id = id_w;
        imie = i;
        nazwisko = n;
    }
    void utworzKurs();
    void dodajModul();
    void dodajLekcje();
    void wyswietlKursantow();
};