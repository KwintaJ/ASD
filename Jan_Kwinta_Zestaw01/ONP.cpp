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

/* struktura reprezentujaca fragment 
   wyrazenia: nawias, operator lub liczbe */
struct Fragment
{
    Fragment(int t): type{t}
    {
    }
    Fragment(int t, char o): type{t}, oper{o}
    {
    }
    Fragment(int t, std::string &n): type{t}, number{n}
    {
    }
    
    int type; // 1 - (
              // 2 - )
              // 3 - operator
              // 4 - number
              
    char oper;
    std::string number;
};

/* funkcja sprawdzajaca czy aktualnie rozwazany fragment jest nawiasem,
   operatorem binarnym czy liczba */
Fragment checkInput(std::string &f)
{    
    if(f[0] == '(')
    {
        f.clear();
        return Fragment(1);
    }
    
    if(f[0] == ')')
    {
        f.clear();
        return Fragment(2);
    }
    
    if(f[0] == '+' || f[0] == '-' || f[0] == '*' || f[0] == '/') 
    {
        char o = f[0];
        f.clear();
        return Fragment(3, o);
    }
    
    std::string n = f;
    f.clear();
    return Fragment(4, n);
}


int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    std::string mathOperation; // dzialanie matematyczne podane na wejsciu
    std::getline(std::cin, mathOperation);
    mathOperation += " ";
    
    std::string output = ""; // wyjscie
    std::string currentFragment = ""; // aktualnie rozwazany fragment wyrazenia
    
    Stack<std::string, MAX_STACK_CAPACITY> Stos; // stos operatorow
    
    for(unsigned int i = 0; i < mathOperation.length(); i++)
    {
        if(mathOperation[i] != ' ')
        {
            currentFragment += mathOperation[i];
            continue;
        }        
        
        /* jesli spacja to sprawdzenie jakiego typu jest 
           ostatni spojny (nierozdzielony spacjami) fragment wyrazenia */
        Fragment x = checkInput(currentFragment); 
        switch(x.type)
        {
            case 1:
                
                break;
            
            case 2:
                
                break;
            
            case 3:
                
                break;
            
            case 4:
                output += x.number + " ";
                break;
        }
    }
    
    std::cout << output << "\n";
}
