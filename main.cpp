#include <iostream>
#include <vector>
using namespace std;

class Uzytkownik {
    private:
        string imie;
        string nazwisko;
        int id;

    public:
        virtual ~Uzytkownik() = 0; // destruktor
};
inline Uzytkownik::~Uzytkownik() {}

class Wykladowca : public Uzytkownik {
    public:
        void utworzKurs();
        void dodajModul();
        void dodajLekcje();
        void wyswietlKursantow();
};

class Kursant : public Uzytkownik {
    private:
        vector<Kurs*> zapisane_kursy;
        vector<Postep> postepy;

    public:
        void zapisNaKurs();
        void wyswietlDostepneKursy();
        void wyswietlPostepy();
        void odbierzCertyfikat(); // zrobi sie po prostu (po wybraniu dla którego kursu) if'a i cout
};

class PlatformaEdukacyjna {
    private:
        vector<Uzytkownik*> uzytkownicy;
        vector<Kurs> kursy;

    public:
        void zarzadzanieUzytkownikami();
};

class Postep {
    private:
        int id_kursu;
        double procent_ukonczenia;
        void aktualizujPostep();
    
    public:
        bool sprawdzCzyOdblokowanoModul();
        bool sprawdzCzyOdblokowanoCeryfikat();
};

class Kurs {
    private:
        int id;
        string nazwa;
        vector<Modul> moduly;
    
    public:
        void wygenerujCertyfikat();
};

class Modul {
    private:
        int id;
        int numer;
        bool czy_odblokowany; // zmienna
        vector<Lekcja> lekcje;
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