#include <iostream>
using namespace std;

class Uzytkownik {
    protected:
        string imie;
        string nazwisko;
        int id;
};

class Wykladowca : public Uzytkownik {
    public:
        void utworzKurs();
        void dodajModul();
        void dodajLekcje();
        void wyswietlKursantow();
};

class Kursant : public Uzytkownik {
    public:
        void zapisNaKurs();
        void wyswietlDostepneKursy();
        void wyswietlPostepy();
        void odbierzCertyfikat(); // zrobi sie po prostu (po wybraniu dla którego kursu) if'a i cout
};

class PlatformaEdukacyjna {
    public:
        void zarzadzanieUzytkownikami();
};

class Postep {
    private:
        int id_kursu;
        double procent_ukonczenia;
    
    public:
        void aktualizujPostep();
        bool sprawdzCzyOdblokowanoModul();
        bool sprawdzCzyOdblokowanoCeryfikat();
};

class Kurs {
    private:
        int id;
        string nazwa;
    
    public:
        void wygenerujCertyfikat();
};

class Modul {
    private:
        int id;
        int numer;
        bool czy_odblokowany; // zmienna
};

class Lekcja {
    private:
        int id;
        string temat;
        bool czy_ukonczona;
    
    public:
        void oznaczJakoUkonczona();
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}