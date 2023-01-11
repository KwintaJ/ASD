//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: Vector.hpp                        //
//                                            //
//    Implementacja wektora                   //
//                                            //
//############################################//

#include <stdexcept>
#include <iostream>

#ifndef VECTOR
#define VECTOR

template<class T>
class Vector
{
public:
    Vector() // Konstruktor pustego wektora
    {
        array = new T[32];
        currentMaxSize = 32;
        currentSize = 0;
    }

    Vector(const Vector& copiedVector) // Konstruktor kopiujacy
    {
        this->currentMaxSize = copiedVector.currentMaxSize;
        this->array = new T[this->currentMaxSize];
        for(this->currentSize = 0; this->currentSize < copiedVector.currentSize; this->currentSize++)
        {
            this->array[this->currentSize] = copiedVector.array[this->currentSize];
        }
    }

    Vector& operator=(const Vector& copiedVector) // Operator kopiowania
    {
        delete[] array;
        this->currentMaxSize = copiedVector.currentMaxSize;
        T *temporaryArray = new T[this->currentMaxSize];
        for(this->currentSize = 0; this->currentSize < copiedVector.currentSize; this->currentSize++)
        {
            temporaryArray[this->currentSize] = copiedVector.array[this->currentSize];
        }
        array = temporaryArray;
        return *this;
    }

    template<class U>
    Vector(U &x, int initSize) // Kostruktor tworzacy initSize-elementowy wektor elementow x
    {
        currentMaxSize = initSize * 2;
        array = new T[currentMaxSize];
        for(currentSize = 0; currentSize < initSize; currentSize++)
        {
            array[currentSize] = std::forward<U>(x);
        }
    }

    ~Vector() // Destruktor
    {
        delete[] array;
    }

    void clear()
    {
        delete[] array;
        T *temporaryArray = new T[32];
        array = temporaryArray;
        currentMaxSize = 32;
        currentSize = 0;
    }
    
    template<class U>
    void push_back(U &&x)
    {
        if(currentSize == currentMaxSize) // zwiekszenie tablicy
        {
            T *temporaryArray = new T[2 * currentMaxSize];
            
            for(int i = 0; i < currentMaxSize; i++)
                temporaryArray[i] = array[i];
               
            delete[] array;
            currentMaxSize *= 2;
            array = temporaryArray;
        }
        
        array[currentSize] = std::forward<U>(x);
        currentSize++;
    }

    T pop_back()
    {
        if(currentSize == 0)
            throw std::out_of_range("underflow");
            
        currentSize--;
        return array[currentSize];
    }

    T &operator[](int pos)
    {    
        return array[pos];
    }

    int size()
    {
        return currentSize;
    }

    bool empty()
    {
        return currentSize == 0;
    }
    
    typedef T* iterator;
    iterator begin()
    {
        return &array[0];
    }
    iterator end()
    {
        return &array[currentSize];
    }

private:
    T *array; // wskaznik na tablice dynamiczna
    int currentMaxSize;
    int currentSize;
};

#endif
