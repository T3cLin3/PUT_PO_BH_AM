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

1. Jako Kursant chcę zapisać się na Kurs, aby móc się uczyć.

2. Jako Kursant chcę otrzymać certyfikat, aby mieć potwierdzenie, że ukończyłem Kurs.

3. Jako Wykładowca chcę utworzyć Kurs, aby Kursanci mogli się uczyć.

4. Jako Wykładowca chcę mieć możliwość sprawdzić listę zapisanych Kursantów, aby wiedzieć czy wszyscy się zapisali.

5. Jako Wykładowca chcę edytować Kursy, aby móc dodawać i usuwać Moduły oraz Lekcje.

6. Jako System, chcę śledzić Postęp nauki Kursanta, aby weryfikować stan zaawansowania.

7. Jako System, chcę blokować Kursantowi dostęp do kolejnego Modułu przed zakończeniem kolejnego, aby wymusić systematyczną naukę.

## Diagram klas

![Diagram klas.jpg](Diagram%20klas.jpg)
