#pragma once
#include <vector>
#include "Uzytkownik.h"
#include "Kurs.h"

class Wykladowca : public Uzytkownik {
public:
    Wykladowca(int id_w, std::string i, std::string n) {
        id = id_w;
        imie = i;
        nazwisko = n;
    }
    void utworzKurs(std::vector<Kurs*>&listaKursow);
    void dodajModul(std::vector<Kurs*>&listaKursow);
    void dodajLekcje();
    void wyswietlKursantow();
};