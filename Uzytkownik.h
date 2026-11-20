#pragma once
#include <string>

class Uzytkownik {
protected:
    std::string imie;
    std::string nazwisko;
    int id;     //ID techniczne użytkownika w systemie
public:
    virtual ~Uzytkownik() = 0; //wirtualny destruktor (usuwanie klas pochodnych)
    int getId() { return id; }
    std::string getImie() { return imie; }
    std::string getNazwisko() { return nazwisko; }
};