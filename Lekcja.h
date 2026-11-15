#pragma once
#include <string>

class Lekcja {
private:
    int id;
    std::string temat;
    bool czy_ukonczona;
public:
    Lekcja(int id_l, std::string t) {
        id = id_l;
        temat = t;
        czy_ukonczona = false;
    }
    int getId() { return id;}
    std::string getTemat() {return temat;}
    bool getCzyUkonczona() {return czy_ukonczona;}
    
    void oznaczJakoUkonczona();
};