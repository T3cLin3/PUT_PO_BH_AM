# Temat 4: Platforma Kursów Online (E-learning)

Wykonujący:
Bartosz Hauff
Adam Musiał

Aktorzy:
Kursant, Wykładowca (dziedziczą po Użytkownik)

Klasy:
Kurs, Moduł, Lekcja, Postęp, PlatformaEdukacyjna

- Wykładowca tworzy kurs i dodaje moduły z lekcjami
- Kursant zapisuje się na kurs i przechodzi przez lekcje w kolejności
- System śledzi postęp i blokuje kolejny moduł do czasu ukończenia poprzedniego
- Po ukończeniu wszyskich modułów system generuje certyfikat

## Opis

Platforma kursów online ma obsługiwać system do E-learningu. Na platformie istnieją Użytkownicy (Wykładowca i Kursanci). Każda osoba posiada imię, nazwisko i numer identyfikacyjny. Każdy Kursant, ma okno startowe, na którym widoczne są Kursy, na które Kursant jest zapisany, oraz jaki jest jego Postęp w danym kursie. Ponadto Kursant widzi, jakie certyfikaty ukończonych Kursów posiada.

W systemie znajdują się Kursy, które podzielone są na moduły, które podzielone są na poszczególne lekcje przygotowywane przez Wykładowcę, który ma pełen dostęp do tworzenie i manipulowania treściami w danym Kursie oraz do listy osób zapisanych na dany Kurs.

Do każdego Kursu Kursant zapisuje się samodzielnie i przechodzi przez lekcje w odpowiedniej kolejności. Do czasu ukończenia danego Modułu przez Kursanta system blokuje dostęp do innych Modułów, dodatkowo system zapisuje, na jakim Module aktualnie jest Kursant.

Po ukończeniu wszystkich modułów w danym kursie Kursant otrzymuje certfikat ukończenia tego kursu.



## User stories

1. Typ: Zarządzanie użytkownikami
   * **Jako** `Kursant`
   * **chcę** zapisać się na wybrany `Kurs`,
   * **aby** uzyskać dostęp do jego materiałów i móc się uczyć.
   * *Kryterium akceptacji:* Wybrany obiekt `Kurs` zostaje dodany do listy `zapisaneKursy` w klasie `Kursant`, a w liście `postepy` tworzony jest nowy obiekt `Postep` przypisany do tego kursu.

2. Typ: Logika biznesowa
   * **Jako** `Kursant`
   * **chcę** przeglądać listę dostępnych kursów oraz widzieć swoje postępy na oknie startowym,
   * **aby** kontrolować stan swojej nauki i wybierać nowe kursy.
   * *Kryterium akceptacji:* Wywołanie metod `wyswietlDostepneKursy()` oraz `wyswietlPostepy()` w klasie `Kursant` prezentuje kursy z listy `listaKursow` oraz wartość atrybutu `procent_ukonczenia` z klasy `Postep`.

3. Typ: Logika biznesowa
   * **Jako** `Kursant`
   * **chcę** realizować kolejne lekcje w module,
   * **aby** systematycznie przyswajać wiedzę z kursu.
   * *Kryterium akceptacji:* Po wywołaniu metody `oznaczJakoUkonczona()` atrybut `czy_ukonczona` w klasie `Lekcja` zmienia wartość na `true`, a atrybut `procent_ukonczenia` w klasie `Postep` zwiększa swoją wartość.

4. Typ: Logika biznesowa
   * **Jako** `Kursant`
   * **chcę** mieć zablokowany dostęp do kolejnego modułu przed ukończeniem poprzedniego,
   * **aby** przechodzić przez materiał w odpowiedniej kolejności.
   * *Kryterium akceptacji:* Atrybut `czy_odblokowany` kolejnego obiektu `Modul` w liście `moduly` pozostaje ustawiony na `false` do momentu, aż wszystkie obiekty `Lekcja` z listy `listaLekcji` w bieżącym module mają atrybut `czy_ukonczona` równy `true`.

5. Typ: Logika biznesowa
   * **Jako** `Kursant`
   * **chcę** otrzymać certyfikat po ukończeniu kursu,
   * **aby** mieć potwierdzenie zdobytych kwalifikacji.
   * *Kryterium akceptacji:* Gdy atrybut `procent_ukonczenia` w klasie `Postep` osiągnie wartość `100` (metoda `sprawdzCzyOdblokowanoCertyfikat()` zwraca `true`), wywoływana jest metoda `wygenerujCertyfikat()` w klasie `Kurs`.

6. Typ: Zarządzanie treścią
   * **Jako** `Wykładowca`
   * **chcę** utworzyć nowy `Kurs`,
   * **aby** udostępnić kursantom materiały do nauki.
   * *Kryterium akceptacji:* Po wywołaniu metody `utworzKurs()` w klasie `Wykładowca` nowy obiekt `Kurs` zostaje dodany do atrybutu `listaKursow` w klasie `PlatformaEdukacyjna`.

7. Typ: Zarządzanie treścią
   * **Jako** `Wykładowca`
   * **chcę** edytować kursy poprzez dodawanie modułów oraz lekcji,
   * **aby** rozbudowywać strukturę dydaktyczną kursu.
   * *Kryterium akceptacji:* Wywołanie metody `dodajModul()` dodaje nowy obiekt `Modul` do listy `moduly` w klasie `Kurs`, a wywołanie `dodajLekcje()` dodaje obiekt `Lekcja` do listy `listaLekcji` w klasie `Modul`.

8. Typ: Zarządzanie treścią
   * **Jako** `Wykładowca`
   * **chcę** sprawdzić listę zapisanych kursantów,
   * **aby** wiedzieć, czy wszyscy studenci zapisali się na kurs.
   * *Kryterium akceptacji:* Wywołanie metody `wyswietlKursantow()` w klasie `Wykładowca` zwraca dane obiektów `Kursant` zapisanych na dany `Kurs`.

9. Typ: Zarządzanie użytkownikami
   * **Jako** `Użytkownik` (`Kursant` lub `Wykładowca`)
   * **chcę** zalogować się do platformy edukacyjnej,
   * **aby** uzyskać dostęp do funkcji przypisanych do mojej roli w systemie.
   * *Kryterium akceptacji:* Wywołanie metody `zarzadzanieUzytkownikami()` w klasie `PlatformaEdukacyjna` weryfikuje rolę użytkownika na podstawie list `listaKursantow` oraz `listaWykladowcow` i udostępnia odpowiedni interfejs.

## Diagram klas

![Diagram klas.jpg](Diagram%20klas.jpg)

## Przypadki użycia i Diagram przypadków użycia

### 1. Zaloguj się do platformy
* **Aktorzy:** Kursant, Wykładowca
* **Opis:** Użytkownik autoryzuje się w systemie (wybiera swoją rolę oraz identyfikator), co pozwala na załadowanie odpowiedniego panelu (Kursanta lub Wykładowcy) z poziomu klasy `PlatformaEdukacyjna`.
* **Powiązanie z User Story:** Odpowiada dziewiątej historii użytkownika (logowanie i zarządzanie dostępem użytkowników).

### 2. Wyświetl dostępne kursy
* **Aktorzy:** Kursant
* **Opis:** Kursant przegląda katalog wszystkich kursów opublikowanych na platformie (`listaKursow`), aby zapoznać się z ich tematyką przed zapisem.
* **Powiązanie z User Story:** Odpowiada drugiej historii użytkownika (przeglądanie oferty kursów).

### 3. Zapisz się na kurs
* **Aktorzy:** Kursant
* **Opis:** Kursant dołącza do wybranego kursu, co powoduje dopisanie kursu do jego listy `zapisaneKursy` oraz zainicjowanie śledzenia postępu (`Postep`) dla tego kursu.
* **Powiązanie z User Story:** Odpowiada pierwszej historii użytkownika (zapis na wybrany kurs).

### 4. Wyświetl postępy
* **Aktorzy:** Kursant
* **Opis:** Kursant sprawdza na oknie startowym listę swoich kursów wraz z procentowym stopniem ich ukończenia (`procent_ukonczenia`) oraz informacją o zdobytych certyfikatach.
* **Powiązanie z User Story:** Odpowiada drugiej historii użytkownika (kontrola stanu nauki na oknie startowym).

### 5. Zrealizuj lekcję
* **Aktorzy:** Kursant
* **Opis:** Kursant zapoznaje się z treścią pojedynczej lekcji w odblokowanym module i oznacza ją jako ukończoną (`oznaczJakoUkonczona()`).
* **Relacje:**
  * `<<include>>` **Zaktualizuj postęp** — każda realizacja lekcji obowiązkowo wywołuje przeliczenie postępu kursanta.
  * `<<extend>>` **Odblokuj kolejny moduł** — realizacja lekcji warunkowo rozszerzana jest o odblokowanie następnego modułu, jeśli była to ostatnia nieukończona lekcja w bieżącym module.
* **Powiązanie z User Story:** Odpowiada trzeciej historii użytkownika (realizacja kolejnych lekcji w module).

### 6. Zaktualizuj postęp
* **Aktorzy:** Brak bezpośredniego aktora (wywoływane automatycznie przez przypadek użycia *Zrealizuj lekcję* w relacji `<<include>>`)
* **Opis:** System przelicza stosunek ukończonych lekcji do wszystkich lekcji w kursie i aktualizuje pole `procent_ukonczenia` w obiekcie klasy `Postep` (`aktualizujPostep()`).
* **Powiązanie z User Story:** Odpowiada trzeciej historii użytkownika (aktualizacja postępu po ukończeniu lekcji).

### 7. Odblokuj kolejny moduł
* **Aktorzy:** Brak bezpośredniego aktora (rozszerza przypadek użycia *Zrealizuj lekcję* w relacji `<<extend>>`)
* **Opis:** Gdy wszystkie lekcje w aktualnym module mają status `czy_ukonczona = true` (metoda `sprawdzCzyOdblokowanoModul()` zwraca `true`), system zmienia atrybut `czy_odblokowany` kolejnego modułu na `true`.
* **Powiązanie z User Story:** Odpowiada czwartej historii użytkownika (blokowanie i odblokowywanie kolejnych modułów w kolejności).

### 8. Odbierz certyfikat
* **Aktorzy:** Kursant
* **Opis:** Po ukończeniu wszystkich modułów w kursie (`procent_ukonczenia == 100`, metoda `sprawdzCzyOdblokowanoCertyfikat()` zwraca `true`) kursant generuje i pobiera imienny certyfikat ukończenia kursu (`wygenerujCertyfikat()`, `odbierzCertyfikat()`).
* **Powiązanie z User Story:** Odpowiada piątej historii użytkownika (otrzymanie certyfikatu po ukończeniu kursu).

### 9. Utwórz nowy kurs
* **Aktorzy:** Wykładowca
* **Opis:** Wykładowca definiuje nowy kurs w systemie, nadając mu identyfikator oraz nazwę (`utworzKurs()`), i rejestruje go w puli kursów na platformie (`listaKursow`).
* **Powiązanie z User Story:** Odpowiada szóstej historii użytkownika (tworzenie nowego kursu).

### 10. Zarządzaj zawartością kursu (Dodaj moduł/lekcje)
* **Aktorzy:** Wykładowca
* **Opis:** Wykładowca rozbudowuje strukturę istniejącego kursu, dodając do niego nowe moduły (`dodajModul()`) oraz przypisując do nich poszczególne lekcje tematyczne (`dodajLekcje()`).
* **Powiązanie z User Story:** Odpowiada siódmej historii użytkownika (edycja kursów poprzez dodawanie modułów i lekcji).

### 11. Wyświetl listę kursantów
* **Aktorzy:** Wykładowca
* **Opis:** Wykładowca pobiera i wyświetla listę wszystkich kursantów zapisanych na prowadzony przez niego kurs (`wyswietlKursantow()`).
* **Powiązanie z User Story:** Odpowiada ósmej historii użytkownika (sprawdzanie listy zapisanych kursantów).

## Diagram przypadków użycia

![Diagram przypadków użycia.jpg](Diagram%20przypadków%20użycia.jpg)

## Diagram sekwencji


### 1. Powiązany przypadek użycia:
* **Nazwa:** Zrealizuj lekcję (wraz z obowiązkową aktualizacją postępu `<<include>>` Zaktualizuj postęp oraz weryfikacją i generowaniem certyfikatu ukończenia kursu).
* **Aktor:** Kursant.

### 2. Cel operacji:
Diagram przedstawia dynamiczny scenariusz realizacji pojedynczej lekcji przez kursanta na platformie e-learningowej, uwzględniający zmianę statusu lekcji, przeliczenie postępu w kursie oraz weryfikację warunku odblokowania certyfikatu (ścieżkę główną kończącą się wygenerowaniem certyfikatu oraz scenariusz alternatywny, gdy wymagania do uzyskania certyfikatu nie są jeszcze spełnione).

### 3. Przebieg interakcji (Krok po kroku):
1. **Inicjacja i ukończenie lekcji:** Kursant wywołuje metodę `oznaczJakoUkonczona()` skierowaną do obiektu `Lekcja`. Obiekt ustawia atrybut `czy_ukonczona` na wartość prawdziwą i zwraca do kursanta komunikat zwrotny `czy_ukonczona : bool (true)`.
2. **Aktualizacja i weryfikacja postępu:** Kursant wywołuje metodę `aktualizujPostep()` na obiekcie `Postęp`, która przelicza aktualny procent ukończenia kursu, a następnie wywołuje metodę `sprawdzCzyOdblokowanoCertyfikat()`, przechodząc do weryfikacji warunku w bloku kombinowanym `alt`.
3. **Ścieżka główna (`[Certyfikat odblokowany]`):** Jeżeli po zaktualizowaniu postępu wszystkie moduły w kursie zostały ukończone, obiekt `Postęp` wywołuje metodę `wygenerujCertyfikat()` na obiekcie `Kurs`. Po wygenerowaniu certyfikatu obiekt `Kurs` zwraca do `Postęp` flagę `potwierdzenie : bool (true)`, a `Postęp` przekazuje końcowy wynik `potwierdzenie : bool (true)` z powrotem do aktora `Kursant`.


![Diagram sekwencji.jpg](Diagram%20sekwencji.jpg)
