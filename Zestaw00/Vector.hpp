//############################################//
//                                            //
//    Jan Kwinta                24.05.2022    //
//                                            //
//    Zestaw00: Implementacja wektora         //
//    Plik: Vector.hpp                        //
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
        array = new T[16];
        maxSize = 16;
        vectorSize = 0;
    }

    Vector(const Vector& other) // Konstruktor kopiujacy
    {
        this->maxSize = other.maxSize;
        this->array = new T[this->maxSize];
        for(this->vectorSize = 0; this->vectorSize < other.vectorSize; this->vectorSize++)
        {
            this->array[this->vectorSize] = other.array[this->vectorSize];
        }
    }

    Vector& operator=(const Vector& other) // Operator kopiowania
    {
        delete[] array;
        this->maxSize = other.maxSize;
        T *temporaryArray = new T[this->maxSize];
        for(this->vectorSize = 0; this->vectorSize < other.vectorSize; this->vectorSize++)
        {
            temporaryArray[this->vectorSize] = other.array[this->vectorSize];
        }
        array = temporaryArray;
        return *this;
    }

    template<class U>
    Vector(U &x, int k) // Kostruktor tworzacy k-elementowy wektor elementow x
    {
        maxSize = k * 2;
        array = new T[maxSize];
        for(vectorSize = 0; vectorSize < k; vectorSize++)
        {
            array[vectorSize] = std::forward<U>(x);
        }
    }

    ~Vector() // Destruktor
    {
        delete[] array;
    }

    void clear()
    {
        delete[] array;
        T *temporaryArray = new T[16];
        array = temporaryArray;
        maxSize = 16;
        vectorSize = 0;
    }
    
    template<class U>
    void push_back(U &&x)
    {
        if(vectorSize == maxSize) // zwiekszenie tablicy
        {
            T *temporaryArray = new T[2 * maxSize];
            
            for(int i = 0; i < maxSize; i++)
                temporaryArray[i] = array[i];
               
            delete[] array;
            maxSize *= 2;
            array = temporaryArray;
        }
        
        array[vectorSize] = std::forward<U>(x);
        vectorSize++;
    }

    T pop_back()
    {
        if(vectorSize == 0)
            throw std::out_of_range("underflow");
            
        vectorSize--;
        return array[vectorSize];
    }

    T &operator[](int pos)
    {    
        return array[pos];
    }

    int size()
    {
        return vectorSize;
    }

    bool empty()
    {
        return vectorSize == 0;
    }
    
    typedef T* iterator;
    iterator begin()
    {
        return &array[0];
    }
    iterator end()
    {
        return &array[vectorSize];
    }

private:
    T *array; // wskaznik na tablice dynamiczna
    int maxSize;
    int vectorSize;
};

#endif