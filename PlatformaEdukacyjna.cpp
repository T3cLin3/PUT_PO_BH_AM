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
    while (true) {
        zarzadzanieUzytkownikami();
    }
}

void PlatformaEdukacyjna::zarzadzanieUzytkownikami() {
    if (zalogowanyUzytkownik == nullptr) {
        zaloguj();
        return;
    }

    if (Kursant* k = dynamic_cast<Kursant*>(zalogowanyUzytkownik)) {
        cout << "\n--- PANEL KURSANTA: " << k->getImie() << " ---\n";
        cout << "1. Wyswietl dostepne kursy\n";
        cout << "2. Zapisz sie na kurs\n";
        cout << "3. Wyswietl postepy\n";
        cout << "4. Odbierz certyfikat\n";
        cout << "0. Wyloguj\n";
        cout << "Wybierz akcje: ";

        int wybor;
        cin >> wybor;

        switch (wybor) {
            case 1: k->wyswietlDostepneKursy(); break;
            case 2: k->zapisNaKurs(); break;
            case 3: k->wyswietlPostepy(); break;
            case 4: k->odbierzCertyfikat(); break;
            case 0: wyloguj(); break;
            default: cout << "Nieznana opcja.\n"; break;
        }
    }
    else if (Wykladowca* w = dynamic_cast<Wykladowca*>(zalogowanyUzytkownik)) {
        cout << "\n--- PANEL WYKLADOWCY: " << w->getImie() << " ---\n";
        cout << "1. Utworz kurs\n";
        cout << "2. Dodaj modul\n";
        cout << "3. Dodaj lekcje\n";
        cout << "4. Wyswietl kursantow\n";
        cout << "0. Wyloguj\n";
        cout << "Wybierz akcje: ";

        int wybor;
        cin >> wybor;

        switch(wybor) {
            case 1: w->utworzKurs(listaKursow); break;
            case 2: w->dodajModul(listaKursow); break;
            case 3: w->dodajLekcje(listaKursow); break;
            case 4: w->wyswietlKursantow(listaKursantow); break;
            case 0 : wyloguj(); break;
            default: cout << "Nieznana opcja. \n"; break;
        }
    }
}