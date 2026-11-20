#pragma once
#include <string>
#include <vector>
#include "Modul.h"

class Kurs{
    private:
        int id;
        std::string nazwa;
        std::vector<Modul> moduly;  //moduły należą wyłącznie do tego kursu
    public:
        Kurs(int id_k,std::string n) {
            id = id_k;
            nazwa = n;
        }
        int getId() {return id;}
        std::string getNazwa() {return nazwa;}

        void dodajModul(const Modul& nowyModul) {
        moduly.push_back(nowyModul);
        }
        std::vector<Modul>& getModuly() {return moduly;}    //referencja żeby modyfikować oryginał a nie kopię
        void wygenerujCertyfikat();
};