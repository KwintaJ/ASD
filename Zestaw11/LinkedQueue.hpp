//############################################//
//                                            //
//    Jan Kwinta                03.06.2023    //
//                                            //
//                                            //
//    Zestaw11: Zadanie Sejfy                 //
//                                            //
//    Plik: LinkedQueue.hpp                   //
//                                            //
//############################################//

#ifndef LLINKEDQUEUE
#define LLINKEDQUEUE

#include <stdexcept>
#include <iostream>

/* Struktura przechowujaca element w kolejce i wskaznik 
   do elementu za nim */
template<class T>
struct queueNode 
{
    queueNode(const T &x): data{x}, next{nullptr}
    {
    }

    T data;
    queueNode<T> *next;
};

template<class T>
class Queue
{
public:
    Queue() // Konstruktor
    {
        currentSize = 0;
        maxSize = 2000000;
        frontNode = nullptr;
        endNode = nullptr;
    }
    template<class U>
    void push(U &&x) // Wstawia element x do kolejki
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        queueNode<T> *newNode = new queueNode<T>(std::forward<U>(x));
        if(currentSize == 0)
        {
            frontNode = newNode;
            endNode = newNode;
        }
        else
        {
            endNode->next = newNode;
            endNode = newNode;
        }
        currentSize++;
    }
    template<class U>
    void enqueue(U &&x)
    {
        if(currentSize == maxSize)
            throw std::out_of_range ("overflow");

        push(std::forward<U>(x));
    }
    T pop() // Usuwa element z kolejki i zwraca jego wartosc
    {
       if(currentSize == 0)
            throw std::out_of_range ("underflow");

        currentSize--;
        T toPop = frontNode->data;
        frontNode = frontNode->next;
        return toPop;
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

        return frontNode->data;
    }
    int size() // Zwraca liczbe elementow w kolejce
    {
        return currentSize;
    }
    bool empty() // Sprawdza czy kolejka jest pusta
    {
        return currentSize == 0;
    }

private:
    queueNode<T> *frontNode; // Wskaznik do elementu na poczatku kolejki
    queueNode<T> *endNode; // Wskaznik do elementu na koncu kolejki
    int currentSize;
    int maxSize;
};

#endif
