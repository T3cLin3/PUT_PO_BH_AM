#pragma once
#include <vector>
#include "Uzytkownik.h"
#include "Kurs.h"
#include "Postep.h"

class Kursant : public Uzytkownik {
private:
    std::vector<Kurs*> zapisaneKursy;
    std::vector<Postep> postepy;
public:
    Kursant(int id_k, std::string i, std::string n){
        id = id_k;
        imie = i;
        nazwisko = n;
    }
    void zapisNaKurs(std::vector<Kurs*>& listaKursow);
    void wyswietlDostepneKursy(std::vector<Kurs*>& listaKursow);
    void wyswietlPostepy();
    void odbierzCertyfikat();
    std::vector<Kurs*>& getZapisaneKursy() { return zapisaneKursy; }
};