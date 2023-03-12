//############################################//
//                                            //
//    Jan Kwinta                24.05.2022    //
//                                            //
//    Zestaw00: Implementacja wektora         //
//    Plik: Vector.cpp                        //
//                                            //
//############################################//

#include "Vector.hpp"
#include "Functions.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Vector<int> Wektor;

    /* ------ wejscie ------ */

    int n; // liczba elementow podanych na wejsciu
    std::cin >> n;
    
    int element;
    while(n--)
    {
        std::cin >> element;
        Wektor.push_back(element);
    }

    /* ------ wyjscie ------ */

    Wektor = sortContainer(Wektor, std::greater<int>());
    if(!Wektor.empty())
        Wektor.pop_back();

    for(auto x : Wektor)
        std::cout << x << " ";
    std::cout << std::endl;

}