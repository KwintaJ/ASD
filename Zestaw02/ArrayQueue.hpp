//############################################//
//                                            //
//    Jan Kwinta                15.10.2022    //
//                                            //
//                                            //
//    Zestaw02: Kolejka                       //
//    Plik: ArrayQueue.hpp                    //
//                                            //
//    Zadanie 1. Implementacja tablicowa      //
//               kolejki                      //
//                                            //
//############################################//

#ifndef ARRAYQUEUE
#define ARRAYQUEUE

#include <stdexcept>
#include <iostream>

template<class T, int N>
class Queue {
public:
    Queue() // Konstruktor
    {
        currentSize = 0;
        frontOfQueue = 0;
        endOfQueue = 0;
        maxSize = N;
        array = new T[N];
    }
    
    template<class U>
    void push(U &&x) // Wstawia element x do kolejki
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        currentSize++;
        array[endOfQueue] = x;
        endOfQueue = (endOfQueue + 1) % maxSize;
    }
    template<class U>
    void enqueue(U &&x)
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");
        
        push(x);
    }
    T pop() // Usuwa element z kolejki i zwraca jego wartosc
    {
       if(currentSize == 0)
            throw std::out_of_range ("underflow");

        currentSize--;
        int poppedIndex = frontOfQueue;
        frontOfQueue = (frontOfQueue + 1) % maxSize;
        return array[poppedIndex];
    }
    T dequeue()
    {
        if(currentSize == 0)
            throw std::out_of_range ("underflow");

        return pop();
    }
    T& front() // Zwraca referencje do pierwszego elementu
    {
        if(currentSize == 0)
            throw std::out_of_range ("underflow");
        
        return array[frontOfQueue];
    }
    int size() // Zwraca liczbę elementow w kolejce
    {
        return currentSize;
    }
    bool empty() // Sprawdza czy kolejka jest pusta
    {
        return currentSize == 0;
    }

private:
    int frontOfQueue; // Indeks tablicy pierwszego (najstarszego) elementu
    int endOfQueue; // Indeks tablicy za ostatnim (najmlodszym) elementem
    int currentSize; 
    int maxSize;
    T *array; // Wskaznik na tablice przechowujaca elementy w kolejce
};

#endif 
