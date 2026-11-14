#pragma once
#include <string>

class Uzytkownik {
protected:
    std::string imie;
    std::string nazwisko;
    int id;
public:
    virtual ~Uzytkownik() = 0;
    int getId() { return id; }
    std::string getImie() { return imie; }
};