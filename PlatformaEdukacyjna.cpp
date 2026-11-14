#include "PlatformaEdukacyjna.h"
#include <iostream>
using namespace std;

//konstruktor - ładujemy testowych użytkowników na sztywno, żeby mieć na czym testować
PlatformaEdukacyjna::PlatformaEdukacyjna() {
    listaKursantow.push_back(new Kursant(1, "Jan", "Kowalski"));
    listaKursantow.push_back(new Kursant(2, "Piotr", "Zalewski"));
    listaWykladowcow.push_back(new Wykladowca(99, "Anna", "Nowak"));
}

void PlatformaEdukacyjna::zaloguj() {
    int podaneId;
    cout << "\n--- PLATFORMA E-LEARNINGOWA ---\n";
    cout << "Podaj swoje ID (testowe ID: 1, 2, 99): ";
    cin >> podaneId;

    //przeszukiwanie wektora kursantów
    for (auto kursant : listaKursantow) {
        if (kursant->getId() == podaneId) {
            zalogowanyUzytkownik = kursant; //przypisanie polimorficzne
            return;
        }
    }
    
    //przeszukujemy wektora wykładowców
    for (auto wykladowca : listaWykladowcow) {
        if (wykladowca->getId() == podaneId) {
            zalogowanyUzytkownik = wykladowca;
            return;
        }
    }

    cout << "Bledne ID. Nie znaleziono uzytkownika w systemie.\n";
}

void PlatformaEdukacyjna::wyloguj() {
    zalogowanyUzytkownik = nullptr;
    cout << "Wylogowano pomyslnie.\n";
}

void PlatformaEdukacyjna::uruchom() {
    bool dziala = true;
    while (dziala) {
        if (zalogowanyUzytkownik == nullptr) {
            zaloguj(); // Blokuje w konsoli, dopóki się nie zalogujesz
        } else {
            // Tymczasowe, proste menu po zalogowaniu
            cout << "\nWitaj, " << zalogowanyUzytkownik->getImie() << "!\n";
            cout << "1. Wyloguj\n";
            cout << "0. Wyjdz z programu\n";
            cout << "Wybierz akcje: ";
            
            int wybor;
            cin >> wybor;
            
            if (wybor == 1) {
                wyloguj();
            } else if (wybor == 0) {
                dziala = false;
            } else {
                cout << "Nieznana opcja.\n";
            }
        }
    }
}

void PlatformaEdukacyjna::zarzadzanieUzytkownikami() {
    cout << "Zarzadzanie uzytkownikami platformy." << endl;
}