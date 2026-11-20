#pragma once
#include <vector>
#include "Uzytkownik.h"
#include "Kurs.h"
#include "Kursant.h"

class Wykladowca : public Uzytkownik {
public:
    Wykladowca(int id_w, std::string i, std::string n) {
        id = id_w;
        imie = i;
        nazwisko = n;
    }
    void utworzKurs(std::vector<Kurs*>&listaKursow);    //dopisuje nowy kurs do listy platformy (referencja)
    void dodajModul(std::vector<Kurs*>&listaKursow);    //modyfikuje moduły wybranego kursu (referencja)
    void dodajLekcje(std::vector<Kurs*>& listaKursow);  //dopisuje lekcje do wybranego modułu (referencja)
    void wyswietlKursantow(std::vector<Kursant*>& listaKursantow);  //wyświetla listę kursantów z platformy
};