//############################################//
//                                            //
//    Jan Kwinta                28.10.2022    //
//                                            //
//                                            //
//    Zestaw03: Lista I                       //
//    Plik: LinkedList.cpp                    //
//                                            //
//    Zadanie 1. Implementacja wskaznikowa    //
//               dwukierunkowa listy          //
//                                            //
//############################################//

#include "LinkedList.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    LinkedList<int> Lista; // stworzenie listy intow

    int n; // liczba instrukcji podanych na wejsciu
    std::cin >> n;

    int elementA, elementB;
    while(n--)
    {
        char instruction; // instrukcja podana na wejsciu
        std::cin >> instruction;
        switch(instruction)
        {
            case 'F':
                /* wstawienie elementu na poczatek listy */
                std::cin >> elementA;
                try
                { 
                    Lista.push_front(elementA);
                }
                catch(const std::out_of_range &oor)
                {
                    std::cerr << oor.what() << "\n";
                }
                break;

            case 'B':
                /* wstawienie elementu na koniec listy */
                std::cin >> elementA;
                try
                {
                    Lista.push_back(elementA);
                }
                catch(const std::out_of_range &oor)
                {
                    std::cerr << oor.what() << "\n";
                }
                break;
                
            case 'f':
                /* wyjecie elementu z poczatku listy */
                try
                {
                    std::cout << Lista.pop_front() << "\n";
                }
                catch(const std::out_of_range &oor)
                {
                    std::cout << "EMPTY" << "\n";
                }
                break;
                
            case 'b':
                /* wyjecie elementu z konca listy */
                try
                {
                    std::cout << Lista.pop_back() << "\n";
                }
                catch(const std::out_of_range &oor)
                {
                    std::cout << "EMPTY" << "\n";
                }
                break;
                
            case 'R':
                /* zastapienie pierwszego wystapienia wartosci
                   x w liscie na element y jezeli to mozliwe */
                std::cin >> elementA >> elementB;
                if(Lista.replace(elementA, elementB))
                {
                    std::cout << "TRUE" << "\n";
                }
                else
                {
                    std::cout << "FALSE" << "\n";
                }
                break;

            case 'S':
                /* wypisanie aktualnej liczby elementow w kolejce */
                std::cout << Lista.size() << "\n";
                break;
        }
    }
}
