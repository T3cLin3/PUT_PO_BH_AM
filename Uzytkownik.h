#pragma once
#include <string>

class Uzytkownik {
private:
    std::string imie;
    std::string nazwisko;
    int id;
public:
    virtual ~Uzytkownik() = 0;
};