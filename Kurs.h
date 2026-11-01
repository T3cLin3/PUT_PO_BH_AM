#pragma once
#include <string>
#include <vector>
#include "Modul.h"

class Kurs{
    private:
        int id;
        std::string nazwa;
        std::vector<Modul> moduly;
    public:
        void wygenerujCertyfikat();
};