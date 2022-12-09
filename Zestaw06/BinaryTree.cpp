//############################################//
//                                            //
//    Jan Kwinta                04.11.2022    //
//                                            //
//                                            //
//    Zestaw06: Binarne drzewo poszukiwań     //
//    Plik: BinaryTree.cpp                    //
//                                            //
//    Zadanie 1. Drzewo binarne               //
//                                            //
//############################################//

#include "BinaryTree.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    BinaryTree<int> Drzewo; // stworzenie drzewa intow

    int n; // liczba elementow podanych na wejsciu
    std::cin >> n;
    
    int element;
    while(n--)
    {
        std::cin >> element;
    }
}
