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
template<class T>
struct stackNode 
{
    stackNode(const T &x): data{x}, next{nullptr}
    {
    }

    T data;
    stackNode<T> *next;
};

template<class T, int N>
class Stack
{
public:
    Stack() // Konstruktor
    {
        currentSize = 0;
        maxSize = N;
        topNode = nullptr;
    }
    template<class U>
    void push(U &&x) // Wstawia element na stos
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        stackNode<T> *input = new stackNode<T>(std::forward<U>(x));
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
    T& top() // Zwraca referencje do najmlodszego elementu
    {
        if(currentSize == 0)
            throw std::out_of_range ("underflow");
        return topNode->data;
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
