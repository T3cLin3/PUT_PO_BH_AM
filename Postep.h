#pragma once
#include "Kurs.h"
#include <set>

class Postep {
private:
    int id_kursu;
    double procent_ukonczenia;
    Kurs* kurs;     //wskaźnik bo Postep nie jest właścicielem kursu (nie tworzy, nie usuwa), wskaźnik żeby widział zmiany w oryginale
    std::set<int> ukonczoneLekcje;
    std::set<int> odblokowaneModuly;
    
public:
    Postep(int id_k, Kurs* k) {
        id_kursu = id_k;
        procent_ukonczenia = 0.0;
        kurs = k;
        for (auto& modul : kurs->getModuly()) {
            if (modul.getCzyOdblokowany()) {
                odblokowaneModuly.insert(modul.getId());
            }
        }
    }
    int getIdKursu() { return id_kursu; }
    double getProcentUkonczenia() { return procent_ukonczenia; }

    void aktualizujPostep();
    bool sprawdzCzyOdblokowanoModul();
    bool sprawdzCzyOdblokowanoCertyfikat();
    void oznaczLekcjeJakoUkonczona(int idLekcji);
    bool czyLekcjaUkonczona(int idLekcji) const;
    bool czyModulOdblokowany(int idModulu) const;
};