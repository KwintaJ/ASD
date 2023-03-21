//############################################//
//                                            //
//    Jan Kwinta                26.03.2023    //
//                                            //
//                                            //
//    Zestaw08: Implementacja kolejki         //
//              priorytetowej                 //
//    Plik: PriorityQueue.cpp                 //
//                                            //
//############################################//

#include "PriorityQueue.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    PriorityQueue<char> KolejkaPriorytetowa;

    /* ------ wejscie ------ */

    int n;
    std::cin >> n;
    
    char element;
    int priority;
    while(n--)
    {
        std::cin >> priority >> element;
        KolejkaPriorytetowa.insert(priority, element);
    }

    /* ------ wyjscie ------ */
    while(!KolejkaPriorytetowa.empty())
    {
        KolejkaPriorytetowa.printQueue();
        KolejkaPriorytetowa.extractMax();
    } 
}

