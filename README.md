# Temat 4: Platforma Kursów Online (E-learning)

**Wykonujący:**
* Bartosz Hauff
* Adam Musiał

**Aktorzy:**
* `Kursant`, `Wykładowca` (dziedziczą po klasie bazowej `Uzytkownik`)

**Klasy:**
* `Uzytkownik`, `Kursant`, `Wykładowca`, `Kurs`, `Modul`, `Lekcja`, `Postep`, `PlatformaEdukacyjna`

**Główne założenia systemu:**
* Wykładowca tworzy kurs i dodaje moduły z lekcjami.
* Kursant zapisuje się na kurs i przechodzi przez lekcje w kolejności.
* System śledzi postęp i blokuje kolejny moduł do czasu ukończenia poprzedniego.
* Po ukończeniu wszystkich modułów system generuje certyfikat.

---

## Opis

Platforma kursów online obsługuje system do e-learningu. Na platformie istnieją Użytkownicy (`Wykładowca` i `Kursant`). Każda osoba posiada imię, nazwisko oraz numer identyfikacyjny. Każdy Kursant ma panel startowy, na którym widoczne są Kursy, na które jest zapisany, jego Postęp procentowy w danym kursie oraz informacja o dostępnych certyfikatach.

W systemie znajdują się Kursy podzielone na moduły, a te z kolei na poszczególne lekcje przygotowywane przez Wykładowcę, który ma pełny dostęp do tworzenia i edycji treści w danym Kursie oraz do podglądu listy osób zapisanych na dany Kurs.

Do każdego Kursu Kursant zapisuje się samodzielnie i przechodzi przez lekcje w odpowiedniej kolejności. Do czasu ukończenia danego Modułu przez Kursanta system blokuje dostęp do kolejnych Modułów. Po ukończeniu wszystkich modułów w danym kursie (osiągnięciu 100% postępu) Kursant może wygenerować certyfikat ukończenia szkolenia.

---

## User Stories

1. **Typ: Zarządzanie użytkownikami**
   * **Jako** `Kursant`
   * **chcę** zapisać się na wybrany `Kurs`,
   * **aby** uzyskać dostęp do jego materiałów i móc się uczyć.
   * *Kryterium akceptacji:* Wybrany obiekt `Kurs` zostaje dodany do listy `zapisaneKursy` w klasie `Kursant`, a w liście `postepy` tworzony jest nowy obiekt `Postep` przypisany do tego kursu.

2. **Typ: Logika biznesowa**
   * **Jako** `Kursant`
   * **chcę** przeglądać listę dostępnych kursów oraz widzieć swoje postępy na oknie startowym,
   * **aby** kontrolować stan swojej nauki i wybierać nowe kursy.
   * *Kryterium akceptacji:* Wywołanie metod `wyswietlDostepneKursy()` oraz `wyswietlPostepy()` w klasie `Kursant` prezentuje kursy z listy `listaKursow` oraz wartość atrybutu `procent_ukonczenia` z klasy `Postep`.

3. **Typ: Logika biznesowa**
   * **Jako** `Kursant`
   * **chcę** realizować kolejne lekcje w module,
   * **aby** systematycznie przyswajać wiedzę z kursu.
   * *Kryterium akceptacji:* Po wywołaniu metody `oznaczJakoUkonczona()` atrybut `czy_ukonczona` w klasie `Lekcja` zmienia wartość na `true`, a atrybut `procent_ukonczenia` w klasie `Postep` zwiększa swoją wartość.

4. **Typ: Logika biznesowa**
   * **Jako** `Kursant`
   * **chcę** mieć zablokowany dostęp do kolejnego modułu przed ukończeniem poprzedniego,
   * **aby** przechodzić przez materiał w odpowiedniej kolejności.
   * *Kryterium akceptacji:* Atrybut `czy_odblokowany` kolejnego obiektu `Modul` w liście `moduly` pozostaje ustawiony na `false` do momentu, aż wszystkie obiekty `Lekcja` z listy `listaLekcji` w bieżącym module mają atrybut `czy_ukonczona` równy `true`.

5. **Typ: Logika biznesowa**
   * **Jako** `Kursant`
   * **chcę** otrzymać certyfikat po ukończeniu kursu,
   * **aby** mieć potwierdzenie zdobytych kwalifikacji.
   * *Kryterium akceptacji:* Gdy atrybut `procent_ukonczenia` w klasie `Postep` osiągnie wartość `100` (metoda `sprawdzCzyOdblokowanoCertyfikat()` zwraca `true`), wywoływana jest metoda `wygenerujCertyfikat()` w klasie `Kurs`.

6. **Typ: Zarządzanie treścią**
   * **Jako** `Wykładowca`
   * **chcę** utworzyć nowy `Kurs`,
   * **aby** udostępnić kursantom materiały do nauki.
   * *Kryterium akceptacji:* Po wywołaniu metody `utworzKurs()` w klasie `Wykładowca` nowy obiekt `Kurs` zostaje dodany do atrybutu `listaKursow` w klasie `PlatformaEdukacyjna`.

7. **Typ: Zarządzanie treścią**
   * **Jako** `Wykładowca`
   * **chcę** edytować kursy poprzez dodawanie modułów oraz lekcji,
   * **aby** rozbudowywać strukturę dydaktyczną kursu.
   * *Kryterium akceptacji:* Wywołanie metody `dodajModul()` dodaje nowy obiekt `Modul` do listy `moduly` w klasie `Kurs`, a wywołanie `dodajLekcje()` dodaje obiekt `Lekcja` do listy `listaLekcji` w klasie `Modul`.

8. **Typ: Zarządzanie treścią**
   * **Jako** `Wykładowca`
   * **chcę** sprawdzić listę zapisanych kursantów,
   * **aby** wiedzieć, czy wszyscy studenci zapisali się na kurs.
   * *Kryterium akceptacji:* Wywołanie metody `wyswietlKursantow()` w klasie `Wykładowca` zwraca dane obiektów `Kursant` zapisanych na dany `Kurs`.

9. **Typ: Zarządzanie użytkownikami**
   * **Jako** `Użytkownik` (`Kursant` lub `Wykładowca`)
   * **chcę** zalogować się do platformy edukacyjnej,
   * **aby** uzyskać dostęp do funkcji przypisanych do mojej roli w systemie.
   * *Kryterium akceptacji:* Wywołanie metody `zarzadzanieUzytkownikami()` w klasie `PlatformaEdukacyjna` weryfikuje rolę użytkownika na podstawie list `listaKursantow` oraz `listaWykladowcow` i udostępnia odpowiedni interfejs.

---

## Diagram klas

[Diagram klas - PDF](./Diagram%20klas.pdf)

---

## Przypadki użycia i Diagram przypadków użycia

### 1. Zaloguj się do platformy
* **Aktorzy:** Kursant, Wykładowca
* **Opis:** Użytkownik autoryzuje się w systemie za pomocą swojego identyfikatora (`ID`), co pozwala na załadowanie odpowiedniego panelu (Kursanta lub Wykładowcy) z poziomu klasy `PlatformaEdukacyjna`.
* **Powiązanie z User Story:** Odpowiada 9. historii użytkownika (logowanie i zarządzanie dostępem użytkowników).

### 2. Wyświetl dostępne kursy
* **Aktorzy:** Kursant
* **Opis:** Kursant przegląda katalog wszystkich kursów opublikowanych na platformie (`listaKursow`), aby zapoznać się z ich tematyką przed zapisem.
* **Powiązanie z User Story:** Odpowiada 2. historii użytkownika (przeglądanie oferty kursów).

### 3. Zapisz się na kurs
* **Aktorzy:** Kursant
* **Opis:** Kursant dołącza do wybranego kursu, co powoduje dopisanie kursu do jego listy `zapisaneKursy` oraz zainicjowanie śledzenia postępu (`Postep`) dla tego kursu.
* **Powiązanie z User Story:** Odpowiada 1. historii użytkownika (zapis na wybrany kurs).

### 4. Wyświetl postępy
* **Aktorzy:** Kursant
* **Opis:** Kursant sprawdza listę swoich kursów wraz z procentowym stopniem ich ukończenia (`procent_ukonczenia`), strukturą odblokowanych modułów oraz informacją o zdobytych certyfikatach.
* **Powiązanie z User Story:** Odpowiada 2. historii użytkownika (kontrola stanu nauki).

### 5. Zrealizuj lekcję
* **Aktorzy:** Kursant
* **Opis:** Kursant zapoznaje się z treścią pojedynczej lekcji w odblokowanym module i oznacza ją jako ukończoną (`oznaczJakoUkonczona()`).
* **Relacje:**
  * `<<include>>` **Zaktualizuj postęp** — każda realizacja lekcji obowiązkowo wywołuje przeliczenie postępu kursanta.
  * `<<extend>>` **Odblokuj kolejny moduł** — realizacja lekcji warunkowo rozszerzana jest o odblokowanie następnego modułu, jeśli była to ostatnia nieukończona lekcja w bieżącym module.
* **Powiązanie z User Story:** Odpowiada 3. historii użytkownika (realizacja kolejnych lekcji w module).

### 6. Zaktualizuj postęp
* **Aktorzy:** Brak bezpośredniego aktora (wywoływane automatycznie przez przypadek użycia *Zrealizuj lekcję* w relacji `<<include>>`)
* **Opis:** System przelicza stosunek ukończonych lekcji do wszystkich lekcji w kursie i aktualizuje pole `procent_ukonczenia` w obiekcie klasy `Postep` (`aktualizujPostep()`).
* **Powiązanie z User Story:** Odpowiada 3. historii użytkownika (aktualizacja postępu po ukończeniu lekcji).

### 7. Odblokuj kolejny moduł
* **Aktorzy:** Brak bezpośredniego aktora (rozszerza przypadek użycia *Zrealizuj lekcję* w relacji `<<extend>>`)
* **Opis:** Gdy wszystkie lekcje w aktualnym module mają status `czy_ukonczona = true` (metoda `sprawdzCzyOdblokowanoModul()` zwraca `true`), system zmienia atrybut `czy_odblokowany` kolejnego modułu na `true`.
* **Powiązanie z User Story:** Odpowiada 4. historii użytkownika (blokowanie i odblokowywanie kolejnych modułów w kolejności).

### 8. Odbierz certyfikat
* **Aktorzy:** Kursant
* **Opis:** Po ukończeniu wszystkich modułów w kursie (`procent_ukonczenia >= 100.0`, metoda `sprawdzCzyOdblokowanoCertyfikat()` zwraca `true`) kursant generuje i odbiera certyfikat ukończenia kursu (`odbierzCertyfikat()`, `wygenerujCertyfikat()`).
* **Powiązanie z User Story:** Odpowiada 5. historii użytkownika (otrzymanie certyfikatu po ukończeniu kursu).

### 9. Utwórz nowy kurs
* **Aktorzy:** Wykładowca
* **Opis:** Wykładowca definiuje nowy kurs w systemie, nadając mu identyfikator oraz nazwę (`utworzKurs()`), i rejestruje go w puli kursów na platformie (`listaKursow`).
* **Powiązanie z User Story:** Odpowiada 6. historii użytkownika (tworzenie nowego kursu).

### 10. Zarządzaj zawartością kursu (Dodaj moduł/lekcje)
* **Aktorzy:** Wykładowca
* **Opis:** Wykładowca rozbudowuje strukturę istniejącego kursu, dodając do niego nowe moduły (`dodajModul()`) oraz przypisując do nich poszczególne lekcje tematyczne (`dodajLekcje()`).
* **Powiązanie z User Story:** Odpowiada 7. historii użytkownika (edycja kursów poprzez dodawanie modułów i lekcji).

### 11. Wyświetl listę kursantów
* **Aktorzy:** Wykładowca
* **Opis:** Wykładowca pobiera i wyświetla listę wszystkich kursantów zapisanych na wybrany kurs (`wyswietlKursantow()`).
* **Powiązanie z User Story:** Odpowiada 8. historii użytkownika (sprawdzanie listy zapisanych kursantów).

[Diagram przypadków użycia - PDF](./Diagram%20przypadków%20użycia.pdf)

---

## Diagram sekwencji

### 1. Powiązany przypadek użycia:
* **Nazwa:** Zrealizuj lekcję oraz Odbierz certyfikat
* **Aktor:** Kursant

### 2. Cel operacji:
Diagram przedstawia dynamiczną interakcję pomiędzy aktorem `Kursant` a obiektami `Lekcja`, `Postęp` oraz `Kurs` podczas zaliczania lekcji, weryfikacji postępu oraz próby odebrania certyfikatu ukończenia szkolenia (ścieżka główna `[Certyfikat odblokowany]` oraz ścieżka alternatywna `[Certyfikat zablokowany]` w bloku kombinowanym `alt`).

### 3. Przebieg interakcji (Krok po kroku):
1. **Inicjacja i ukończenie lekcji:** Kursant wywołuje metodę `oznaczJakoUkonczona()` na obiekcie `Lekcja`. Obiekt zmienia status atrybutu `czy_ukonczona` na `true` i zwraca potwierdzenie `czy_ukonczona: bool (true)`.
2. **Aktualizacja postępu i odblokowanie modułu:** Kursant wywołuje kolejno metody `aktualizujPostep()` oraz `sprawdzCzyOdblokowanoModul()` na obiekcie `Postęp`, który przelicza procent ukończenia kursu i w razie potrzeby odblokowuje kolejny moduł, zwracając `wynik: bool`.
3. **Weryfikacja uprawnień do certyfikatu:** Kursant wywołuje metodę `sprawdzCzyOdblokowanoCertyfikat()` na obiekcie `Postęp`, otrzymując zwrotnie `wynik: bool`.
4. **Ścieżka główna (`[wynik == true]`):** Jeżeli kurs został ukończony w 100%, Kursant wywołuje metodę `wygenerujCertyfikat()` na obiekcie `Kurs`, co skutkuje wyświetleniem certyfikatu w konsoli.
5. **Ścieżka alternatywna (`[wynik == false]`):** Jeżeli warunek ukończenia nie został spełniony, system wyświetla komunikat o braku 100% postępu bez wywoływania generowania certyfikatu.

[Diagram sekwencji - PDF](./Diagram%20sekwencji.pdf)

---

## Projekt C++

### Architektura i zastosowane mechanizmy Programowania Obiektowego (OOP)
Aplikacja została zaimplementowana jako program konsolowy w języku **C++** z podziałem na pliki nagłówkowe (`.h`) oraz pliki źródłowe (`.cpp`):
* **Hermetyzacja:** Wszystkie atrybuty klas (`id`, `imie`, `nazwisko`, `moduly`, `listaLekcji`, `procent_ukonczenia`) są ukryte w sekcjach `private` lub `protected`, a dostęp do nich odbywa się wyłącznie przez publiczne metody (gettery, settery oraz metody logiki biznesowej).
* **Dziedziczenie i Polimorfizm:** Klasy `Kursant` oraz `Wykładowca` dziedziczą publicznie po klasie bazowej `Uzytkownik`. Zarządzanie sesją zalogowanego użytkownika w klasie `PlatformaEdukacyjna` opiera się na wskaźniku typu bazowego `Uzytkownik* zalogowanyUzytkownik` oraz bezpiecznym rzutowaniu w dół (`dynamic_cast<Kursant*>` oraz `dynamic_cast<Wykladowca*>`), co umożliwia dynamiczne wyświetlenie odpowiedniego menu dla danej roli.
* **Kompozycja vs Agregacja:**
  * Struktura `Kurs` -> `Modul` -> `Lekcja` oraz lista `postepy` w klasie `Kursant` zostały zrealizowane jako **kompozycja** (`std::vector<T>`), ponieważ obiekty podrzędne są integralną częścią obiektu nadrzędnego.
  * Współdzielone zasoby (`listaKursow`, `listaKursantow`, `listaWykladowcow` w `PlatformaEdukacyjna` oraz `zapisaneKursy` w `Kursant`) wykorzystują wektory wskaźników (`std::vector<T*>`), aby operować na tych samych instancjach obiektów w pamięci.
* **Zarządzanie pamięcią:** Klasa bazowa `Uzytkownik` posiada wirtualny destruktor (`virtual ~Uzytkownik() = default;`), a destruktor `~PlatformaEdukacyjna()` zwalnia za pomocą operatora `delete` wszystkie obiekty zaalokowane dynamicznie operatorem `new`, zapobiegając wyciekom pamięci.

### Struktura plików
* `main.cpp` — punkt wejścia programu, inicjalizacja i uruchomienie platformy.
* `PlatformaEdukacyjna.h` / `PlatformaEdukacyjna.cpp` — główna pętla aplikacji, logowanie/wylogowywanie, zarządzanie sesją oraz ładowanie startowej bazy danych.
* `Uzytkownik.h` / `Uzytkownik.cpp` — klasa bazowa dla użytkowników systemu.
* `Kursant.h` / `Kursant.cpp` — obsługa zapisów na kursy, przeglądania oferty, realizacji lekcji oraz odbioru certyfikatów.
* `Wykladowca.h` / `Wykladowca.cpp` — tworzenie kursów, dodawanie modułów i lekcji oraz podgląd zapisanych kursantów.
* `Kurs.h` / `Kurs.cpp` — reprezentacja kursu, zarządzanie modułami oraz generowanie certyfikatu.
* `Modul.h` / `Modul.cpp` — reprezentacja modułu kursu oraz kontrola jego odblokowania.
* `Lekcja.h` / `Lekcja.cpp` — reprezentacja pojedynczej lekcji i jej statusu ukończenia.
* `Postep.h` / `Postep.cpp` — obliczanie procentowego postępu nauki oraz logika odblokowywania kolejnych modułów i certyfikatu.

### Kompilacja i uruchomienie
Aby skompilować projekt za pomocą kompilatora `g++` (standard C++11 lub nowszy), należy wykonać w katalogu głównym projektu polecenie:

```bash
g++ *.cpp -o main.exe