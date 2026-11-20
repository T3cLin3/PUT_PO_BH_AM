#pragma once
#include <vector>
#include "Lekcja.h"

class Modul {
private:
    int id;     //numer id w systemie
    int numer;  //numer wyświetlany kursantowi (każdy kurs może mieć moduł 1, 2 itp)
    bool czy_odblokowany;
    std::vector<Lekcja> listaLekcji;    //lekcje należą do tego modułu
public:
    Modul(int id_m , int nr,bool odblokowany) {
        id = id_m;
        numer = nr;
        czy_odblokowany = odblokowany;
    }
    int getId() {return id;}
    int getNumer() {return numer;}
    bool getCzyOdblokowany() {return czy_odblokowany;}
    void setCzyOdblokowany(bool stan) {czy_odblokowany = stan;}

void dodajLekcje(const Lekcja& nowaLekcja) {
        listaLekcji.push_back(nowaLekcja);
    }
    std::vector<Lekcja>& getListaLekcji() {return listaLekcji;}
};