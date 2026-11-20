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

    Uzytkownik* zalogowanyUzytkownik = nullptr; //wskaźnik sesji (nullptr - nikt nie jest zalogowany)
    bool czyDziala = true;  //flaga sterująca główną pętlą programu
public:
    PlatformaEdukacyjna();  //konstruktor do wgrania danych testowych
    ~PlatformaEdukacyjna();
    PlatformaEdukacyjna(const PlatformaEdukacyjna&) = delete;
    PlatformaEdukacyjna& operator=(const PlatformaEdukacyjna&) = delete;
    void uruchom();        //główna pętla konsoli
    void zaloguj();
    void wyloguj();
    void zarzadzanieUzytkownikami();
};