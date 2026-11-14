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

    Uzytkownik* zalogowanyUzytkownik = nullptr; //wskaźnik na bieżącą sesję
public:
    PlatformaEdukacyjna();  //konstruktor do wgrania danych testowych
    void uruchom();        //główna pętla konsoli
    void zaloguj();
    void wyloguj();
    void zarzadzanieUzytkownikami();
};