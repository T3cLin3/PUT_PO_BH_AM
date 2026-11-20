#include <iostream>
#include "PlatformaEdukacyjna.h"
using namespace std;

int main() {
    cout << "Uruchamianie Platformy Edukacyjnej..." << endl;
    PlatformaEdukacyjna platforma;
    platforma.uruchom();
    return 0;
}
// w WSL (jakieś ograniczenia windowsa blokują normalne uruchomienie)
// cd "/mnt/d/Users/asass/Desktop/Programowanie - sem3/Laby - po/PUT_PO_BH_AM"
// g++ *.cpp -o main && ./main