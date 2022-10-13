//############################################//
//                                            //
//    Jan Kwinta                07.10.2022    //
//                                            //
//                                            //
//    Zestaw01: Stos                          //
//    Plik: LinkedStack.hpp                   //
//                                            //
//    Zadanie 2. Implementacja wskaznikowa    //
//               stosu                        //
//                                            //
//############################################//

#ifndef LLINKEDSTACK
#define LLINKEDSTACK

#include <stdexcept>
#include <iostream>

/* Struktura przechowujaca element na stosie i wskaznik 
   do elementu ponizej */
template<typename T>
struct stackNode 
{
    stackNode(const T &x): data{x}, next{nullptr}
    {
    }

    T data;
    stackNode<T> *next;
};

template<typename T>
class Stack
{
public:
    Stack(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
    {
        currentSize = 0;
        maxSize = capacity;
        topNode = nullptr;
    }
    void push(T &x) // Wstawia element na stos
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        stackNode<T> *input = new stackNode<T>(x);
        input->next = topNode;
        topNode = input;

        currentSize++;
    }
    T pop() // Usuwa element ze stosu i zwraca jego wartosc
    {
        if(currentSize == 0)
            throw std::out_of_range ("underflow");

        stackNode<T> *output = topNode;
        topNode = topNode->next;
        currentSize--;
        return output->data;   
    }
    int size() // Zwraca liczbe elementow na stosie
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
    stackNode<T> *topNode; // Wskaznik do elementu na szczycie stosu
};

#endif
