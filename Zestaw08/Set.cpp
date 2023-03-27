//############################################//
//                                            //
//    Jan Kwinta                19.03.2023    //
//                                            //
//                                            //
//    Zestaw08: Implementacja zbioru          //
//    Plik: Set.cpp                           //
//                                            //
//############################################//

#include "Set.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Set<int> Zbior1;
    Set<int> Zbior2;

    /* ------ wejscie ------ */

    int n, m; // liczba elementow podanych na wejsciu
    std::cin >> n >> m;
    
    int element;
    while(n--)
    {
        std::cin >> element;
        Zbior1.insert(element);
    }
    while(m--)
    {
        std::cin >> element;
        Zbior2.insert(element);
    }

    /* ------ wyjscie ------ */
    std::cout << "Zbior1: ";
    Zbior1.printSet();
    std::cout << "Zbior2: ";
    Zbior2.printSet();
    
    
    if(Zbior1.isMember(6))
    {
        std::cout << "Liczba 6 jest elementem Zbioru1. Zostanie teraz usunieta" << std::endl;
        Zbior1.remove(6);
    }
    else
        std::cout << "Liczba 6 nie jest elementem Zbioru1" << std::endl;
    
    if(Zbior2.size() > 0)
    {
        std::cout << "Zbior2 jest niepusty" << std::endl;
        int usuniety = Zbior2.pop();
        std::cout << "Ze Zbioru2 zostala usunieta liczba " << usuniety << std::endl;
    }
    else
        std::cout << "Zbior2 jest pusty" << std::endl;
        
        
    std::cout << "Rozmiary obydwu zbiorow: Zbior1 - " << Zbior1.size();
    std::cout << ", Zbior2 - " << Zbior2.size() << std::endl << std::endl;

    std::cout << "Zbior1: ";
    Zbior1.printSet();
    std::cout << "Zbior2: ";
    Zbior2.printSet();
    

    std::cout << "Przeciecie: ";
    Set<int> I = Zbior1.intersection(Zbior2);
    I.printSet();

    std::cout << "Roznica: ";
    Set<int> D = Zbior1.difference(Zbior2);
    D.printSet();

    std::cout << "Suma: ";
    Set<int> U = Zbior1._union(Zbior2);
    U.printSet();
}