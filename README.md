# Sydor Ewa Antonina
# Szymczyk Edyta Marta

Ma to być symulator piłkarskiego turnieju Ligi Mistrzów. Najpierw losowanie 32 drużyn, i ich podziału na grupy, tabele punktowe.

Później etap 1/8, 1/4, półfinały i finał, z wynikami wyświetlanymi na ekranie. Obiekt drużyny ma mieć 8 parametrów - obrona, pomoc, atak, posiadanie piłki, strzały, gole, grupa, punkty w tabeli. 

Wygrana determinowana przez gole, a szansa ich strzelenia przez stosunek posiadania piłki. Decyduje on o ilości szans na strzał, każda ma maksymalnie 10, proporcjonalnie podzielone. Żeby był celny - losowanie, w którym większą szansę ma drużyna z lepszym atakiem od obrony przeciwnika.

## Symulacja turnieju piłki nożnej

Etapami turnieju będą faza grupowa, ćwierćfinały, półfinały, finał (oraz mecze o miejsca 3-8). Każda z 16 drużyn będzie losowana do jednej z 4 grup. Drużyna będzie miała na początek kilka parametrów, takich jak doświadczenie, skuteczność ataku/obrony. W fazie grupowej drużyny grają „każdy z każdym”, otrzymują punkty za zwycięstwo lub remis, nie otrzymują za porażkę. Podczas meczu na postawę drużyny mają wpływ takie czynniki jak pogoda, dyspozycja dnia, kontuzje. Stosowane będą funkcje takie jak strzelenie gola, faule/kartki zależne od jakichś parametrów (szczęście, skuteczność napastnika, obrońców itp.). 

Wygrana drużyna zyskuje punkty doświadczenia, zależne od doświadczenia pokonanej drużyny, a przegrani nie otrzymują punktów lub tracą je, jeśli przegrają z teoretycznie słabszą drużyną. Po każdym meczu wyświetlany jest opis jego przebiegu – wynik, ważniejsze zdarzenia, konsekwencje punktowe dla drużyny. Sam turniej przebiega na zasadach zbliżonych do tych rozgrywanych realnie (zasady wyjścia z grupy, wyłaniania zwycięzcy w fazie walki o poszczególne miejsca). Na koniec prezentowane są lokaty poszczególnych drużyn.
