#pragma once

class Postep {
private:
    int id_kursu;
    double procent_ukonczenia;
    void aktualizujPostep();
public:
    bool sprawdzCzyOdblokowanoModul();
    bool sprawdzCzyOdblokowanoCertyfikat();
};