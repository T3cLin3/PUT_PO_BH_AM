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

## User stories

1. Jako Kursant chcę przeglądać listę dostępnych Kursów na platformie, aby wybrać interesujący mnie temat nauki.

2. Jako Kursant chcę samodzielnie zapisać się na wybrany Kurs, aby uzyskać dostęp do jego materiałów.

3. Jako Kursant chcę widzieć na oknie startowym listę moich Kursów, aktualny Postęp w każdym z nich oraz zdobyte certyfikaty, aby kontrolować stan swojej nauki.

4. Jako Kursant chcę realizować Lekcje w odpowiedniej kolejności i oznaczać je jako ukończone, aby systematycznie przyswajać wiedzę i odblokowywać kolejne Moduły.

5. Jako Kursant chcę mieć zablokowany dostęp do kolejnego Modułu do czasu ukończenia poprzedniego, aby przechodzić przez materiał zgodnie z założoną strukturą Kursu.

6. Jako Kursant chcę otrzymać certyfikat po ukończeniu wszystkich Modułów w Kursie, aby mieć potwierdzenie zdobytych kwalifikacji.

7. Jako Wykładowca chcę utworzyć nowy Kurs, aby udostępnić Kursantom nową ścieżkę kształcenia.

8. Jako Wykładowca chcę zarządzać zawartością Kursu (dodawać Moduły oraz Lekcje), aby rozbudowywać materiały dydakt
yczne.
9. Jako Wykładowca chcę wyświetlić listę Kursantów zapisanych na dany Kurs, aby weryfikować frekwencję i zainteresowanie zajęciami.

## Diagram klas

![Diagram klas.jpg](Diagram%20klas.jpg)
