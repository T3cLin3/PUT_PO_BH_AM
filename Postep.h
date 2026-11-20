#pragma once
#include "Kurs.h"

class Postep {
private:
    int id_kursu;
    double procent_ukonczenia;
    Kurs* kurs;     //wskaźnik bo Postep nie jest właścicielem kursu (nie tworzy, nie usuwa), wskaźnik żeby widział zmiany w oryginale
    
public:
    Postep(int id_k, Kurs* k) {
        id_kursu = id_k;
        procent_ukonczenia = 0.0;
        kurs = k;
    }
    int getIdKursu() { return id_kursu; }
    double getProcentUkonczenia() { return procent_ukonczenia; }

    void aktualizujPostep();
    bool sprawdzCzyOdblokowanoModul();
    bool sprawdzCzyOdblokowanoCertyfikat();
};