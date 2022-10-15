 //############################################//
//                                            //
//    Jan Kwinta                07.10.2022    //
//                                            //
//                                            //
//    Zestaw01: Stos                          //
//    Plik: ONP.cpp                           //
//                                            //
//    Zadanie 5. Odwrotna notacja polska      //
//                                            //
//############################################//

#include "ArrayStack.hpp"

#include <iostream>
#include <string>

const int MAX_STACK_CAPACITY = 1000000;

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    std::string mathOperation; // dzialanie matematyczne podane na wejsciu
    std::getline(std::cin, mathOperation);

    mathOperation += " "; // sztuczna spacja na koncu wejscia, aby 
                          // instrukcje w liniach 47 - 75 wykonaly sie
                          // rowniez po wczytaniu ostatniego ")"
    
    std::string output = ""; // wyjscie
    std::string currentFragment = ""; // aktualnie rozwazany fragment wyrazenia
    
    Stack<std::string, MAX_STACK_CAPACITY> Stos; // stos operatorow
    
    for(unsigned int i = 0; i < mathOperation.length(); i++)
    {
        if(mathOperation[i] != ' ')
        {
            /* wszystko co nie jest spacja dodajemy do zmiennej 
               przechowujacej aktualnie rozwazany fragment wyrazenia */
            currentFragment += mathOperation[i];
            continue;
        }        
        
        /* jesli napotkamy spacje to sprawdzamy jakiego typu jest 
           ostatni spojny (nierozdzielony spacjami) fragment wyrazenia:
           moze byc nawiasem, operatorem binarnym lub liczba */
        if(currentFragment[0] == '(')
        {
            /* nawiasy otwierajace mozna zingnorowac */
            currentFragment.clear();
            continue;
        }
        if(currentFragment[0] == '+' || currentFragment[0] == '-' || currentFragment[0] == '*' || currentFragment[0] == '/') 
        {
            /* kazdy napotkany operator dodajemy na stos */
            Stos.push(currentFragment);
            currentFragment.clear();
            continue;
        }
        if(currentFragment[0] == ')')
        {
            /* nawias zamykajacy - wyciagamy ostatnio uzyty 
               operator (na gorze stosu) i dokladamy do outputu */
            output += Stos.pop();
            currentFragment.clear();
        }
        else
        {
            /* w przeciwnym razie fragment jest liczba - po prostu
               dodajemy ja do outputu */
            output += currentFragment;
            currentFragment.clear();  
        }
        
        if(i != (mathOperation.length() - 1))
        {
            output += " ";
        }
    }
    
    /* wypisanie odpowiedzi */
    std::cout << output << "\n";
}
