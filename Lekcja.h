#pragma once
#include <string>

class Lekcja {
private:
    int id;
    std::string temat;
    bool czy_ukonczona;
public:
    void oznaczJakoUkonczona();
};