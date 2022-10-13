//############################################//
//                                            //
//    Jan Kwinta                07.10.2022    //
//                                            //
//                                            //
//    Zestaw01: Stos                          //
//    Plik: ArrayStack.hpp                    //
//                                            //
//    Zadanie 1. Implementacja tablicowa      //
//               stosu                        //
//                                            //
//############################################//

#ifndef ARRAYSTACK
#define ARRAYSTACK

#include <stdexcept>
#include <iostream>

template<typename T>
class Stack {
public:
    Stack(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
    {
        currentSize = 0;
        maxSize = capacity;
        array = new T[capacity];
    }
    void push(T &x) // Wstawia element na stos
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        array[currentSize] = x;
        currentSize++;
    }
    T pop() // Usuwa element ze stosu i zwraca jego wartosc
    {
       if(currentSize == 0)
            throw std::out_of_range ("underflow");

        currentSize--;
        return array[currentSize];
    }
    int size() // Zwraca liczbę elementow na stosie
    {
        return currentSize;
    }
    bool empty() // Sprawdza czy stos jest pusty
    {
        return currentSize == 0;
    }

private:
    int currentSize;
    int maxSize;
    T *array; // Wskaznik na tablice przechowujaca elementy na stosie
};

#endif 
