#pragma once

class Postep {
private:
    int id_kursu;
    double procent_ukonczenia;
    
public:
    void aktualizujPostep();
    bool sprawdzCzyOdblokowanoModul();
    bool sprawdzCzyOdblokowanoCertyfikat();
};