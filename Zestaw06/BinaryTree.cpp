//############################################//
//                                            //
//    Jan Kwinta                09.12.2022    //
//                                            //
//                                            //
//    Zestaw06: Binarne drzewo poszukiwan     //
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


    /* ------ wejscie ------ */

    int n; // liczba elementow podanych na wejsciu
    std::cin >> n;
    
    int element;
    while(n--)
    {
        std::cin >> element;
        Drzewo.insert(element); // wlozenie elementu do drzewa
    }

    /* ------ wyjscie ------ */

    std::cerr << std::endl;

    std::cout << Drzewo.size() << " "            // liczba elementow
              << Drzewo.depth() << " "           // wysokosc
              << Drzewo.minimum() << " "         // element najmniejszy
              << Drzewo.maximum() << std::endl;  // element najwiekszy

    Drzewo.preorder(); // wypisanie wszystkich elementow w kolejnosci preorder

    /* dla kazdej z liczb od 1 do 9 sprawdzenie czy znajduje sie w drzewie */
    for(int i = 1; i <= 9; i++)
    {
        if(Drzewo.search(i) == nullptr)
            std::cout << "No" << std::endl;
        else       
            std::cout << "Yes" << std::endl;
    }
}
