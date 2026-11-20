#pragma once
#include <vector>
#include "Uzytkownik.h"
#include "Kurs.h"
#include "Postep.h"

class Kursant : public Uzytkownik {
private:
    std::vector<Kurs*> zapisaneKursy;   //wskaźniki na współdzielone kursy - właścicielem PlatformaEdukacyjna
    std::vector<Postep> postepy;    //prywatne postępy kursanta
public:
    Kursant(int id_k, std::string i, std::string n){
        id = id_k;
        imie = i;
        nazwisko = n;
    }
    void zapisNaKurs(std::vector<Kurs*>& listaKursow);      //modyfikowanie oryginalnych wektorów bez kopiowania (referencja)
    void wyswietlDostepneKursy(std::vector<Kurs*>& listaKursow);    //odczyt całej listy bez jej kopiowania (referencja)
    void wyswietlPostepy();
    void odbierzCertyfikat();
    std::vector<Kurs*>& getZapisaneKursy() { return zapisaneKursy; }    //zwraca referencję, aby nie kopiować wektoru
};