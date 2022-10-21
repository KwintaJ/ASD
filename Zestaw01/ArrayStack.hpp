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

template<class T, int N>
class Stack {
public:
    Stack() // Konstruktor
    {
        currentSize = 0;
        maxSize = N;
        array = new T[N];
    }
    
    template<class U>
    void push(U &&x) // Wstawia element na stos
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        array[currentSize] = std::forward<U>(x);
        currentSize++;
    }
    T pop() // Usuwa element ze stosu i zwraca jego wartosc
    {
       if(currentSize == 0)
            throw std::out_of_range ("underflow");

        currentSize--;
        return array[currentSize];
    }
    T& top() // Zwraca referencje do najmlodszego elementu
    {
        if(currentSize == 0)
            throw std::out_of_range ("underflow");
        return array[currentSize - 1];
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
