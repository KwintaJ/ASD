//############################################//
//                                            //
//    Jan Kwinta                15.10.2022    //
//                                            //
//                                            //
//    Zestaw02: Kolejka                       //
//    Plik: Queue.cpp                         //
//                                            //
//    Zadanie 3. Kolejka                      //
//                                            //
//############################################//

#include "LinkedQueue.hpp"

#include <iostream>
#include <string>

const int MAX_QUEUE_SIZE = 1000000;

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Queue<int, MAX_QUEUE_SIZE> Kolejka; // stworzenie kolejki intow

    int n; // liczba instrukcji podanych na wejsciu
    std::cin >> n;
    while(n--)
    {
        char instruction; // instrukcja podana na wejsciu
        std::cin >> instruction;
        switch(instruction)
        {
            case 'A':
                /* wstawienie elementu do kolejki */
                int element;
                std::cin >> element;
                try
                { 
                    Kolejka.push(element);
                }
                catch(const std::out_of_range &oor)
                {
                    std::cerr << oor.what() << "\n";
                }
                break;

            case 'D':
                /* wyciagniecie elementu z kolejki */
                try
                {
                    std::cout << Kolejka.pop() << "\n";
                }
                catch(const std::out_of_range &oor)
                {
                    std::cout << "EMPTY\n";
                }
                break;

            case 'S':
                /* wypisanie aktualnej liczby elementow w kolejce */
                std::cout << Kolejka.size() << "\n";
                break;
        }
    }
}
