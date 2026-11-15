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
    bool czyDziala = true;
public:
    PlatformaEdukacyjna();  //konstruktor do wgrania danych testowych
    ~PlatformaEdukacyjna();
    void uruchom();        //główna pętla konsoli
    void zaloguj();
    void wyloguj();
    void zarzadzanieUzytkownikami();
};