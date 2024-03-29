###############################################################################
#  Autor: Jan Kwinta                                       Krakow, 15.01.2023 #
#  Projekt: Prostokat                                                         #
###############################################################################

* Zawartosc:
===============================================================================
Katalog Projekt zawiera nastepujace podkatalogi i pliki:

- tests                 #   Katalog z danymi testowymi
    |                   #
    |- in               #   Dane wejsciowe
    |   |               #
    |   |- 0.in         #
    |   |- 1.in         #
    |   |- 2.in         #
    |   |  ...          #
    |                   #
    |-out               #   Wzorcowe dane wyjsciowe
    |   |               #
    |   |- 0.out        #
    |   |- 1.out        #
    |   |- 2.out        #
    |   | ...           #
    |                   #
    |-toTest            #   Wyjscie programu Prostokat.x
        |               #
        |- 0.out        #
        |- 1.out        #
        |- 2.out        #
        | ...           #
                        #
- README                #   Ten plik 
- Makefile              #   Plik do kompilacji
                        #
- Prostokat.cpp         #   Plik zrodlowy programu wzorcowego
- Generator.cpp         #   Plik zrodlowy programu do generowania danych 
                        #   wejsciowych
- ProstokatBrute.cpp    #   Plik zrodlowy programu wykorzystujacego brute-force
                        #   do generowania wzorcowych danych wyjściowych
- Tester.cpp            #   Plik zrodlowy programu do testowania Prostokat.x
                        #
- Functions.hpp         #   Pliki naglowkowe z implementacjami potrzebnych
- Point.hpp             #   kontenerow i funkcji
- IntervalTree.hpp      #   
- Vector.hpp            #   
- LinkedQueue.hpp       #
===============================================================================


* Opisy programow:
_______________________________________________________________________________

Prostokat.x

    Dany jest zbior n punktow na plaszczyznie o wspolrzędnych calkowitych.
    Chcemy ustawic dany prostokat w ten sposob, aby w jego wnetrzu znalazlo
    sie mozliwie jak najwiecej punktow.
    
    Program wczytuje ze standardowego wejscia:
    
        - liczbe w - szerokosc prostokata
        - liczbe h - wysokosc prostokata
        - liczbe n - liczbe puntkow na plaszczyznie
        - n punktow w postaci par wspolrzednych (x, y)
        
    Obslugujac powyzsze zakladamy, ze:
        - Kazda wczytana liczba jest calkowita
        - 1 <= w, h <= 10000
        - 1 <= n <= 15000
        - -30000 <= x, y <= 30000
        
    Program na standardowe wyjscie wypisuje jedna liczbe calkowita: 
        Maksymalna liczba punktow, ktora moze obejmowac prostokat.
        
_______________________________________________________________________________

