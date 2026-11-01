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
    void zapisNaKurs();
    void wyswietlDostepneKursy();
    void wyswietlPostepy();
    void odbierzCertyfikat();
};