#pragma once
#include <string>

class Lekcja {
private:
    int id;
    std::string temat;
public:
    Lekcja(int id_l, std::string t) {
        id = id_l;
        temat = t;
    }
    int getId() { return id;}
    std::string getTemat() {return temat;}
};