//############################################//
//                                            //
//    Jan Kwinta                07.10.2022    //
//                                            //
//                                            //
//    Zestaw01: Stos                          //
//    Plik: Stack.cpp                         //
//                                            //
//    Zadanie 3. Stos                         //
//                                            //
//############################################//

#include "LinkedStack.hpp"

#include <iostream>
#include <string>

const int MAX_STACK_CAPACITY = 1000000;

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Stack<int, MAX_STACK_CAPACITY> Stos; // stworzenie stosu intow

    int n; // liczba instrukcji podanych na wejsciu
    std::cin >> n;
    while(n--)
    {
        char instruction; // instrukcja podana na wejsciu
        std::cin >> instruction;
        switch(instruction)
        {
            case 'A':
                /* wstawienie elementu do stosu */
                int element;
                std::cin >> element;
                try
                { 
                    Stos.push(element);
                }
                catch(const std::out_of_range &oor)
                {
                    std::cerr << oor.what() << "\n";
                }
                break;

            case 'D':
                /* wyciagniecie elementu ze stosu */
                try
                {
                    std::cout << Stos.pop() << "\n";
                }
                catch(const std::out_of_range &oor)
                {
                    std::cout << "EMPTY\n";
                }
                break;

            case 'S':
                /* wypisanie aktualnej liczby elementow na stosie */
                std::cout << Stos.size() << "\n";
                break;
        }
    }
}
