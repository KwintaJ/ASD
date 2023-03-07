//############################################//
//                                            //
//    Jan Kwinta                19.03.2023    //
//                                            //
//                                            //
//    Zestaw08: Implementacja zbioru          //
//    Plik: Set.hpp                           //
//                                            //
//############################################//

#include <stdexcept>
#include <algorithm>
#include <iostream>

#ifndef SET
#define SET

template<class T>
class Set
{    
public:
    Set()
    {
        array = new T[8];
        maxSize = 8;
        setSize = 0;
    }

    ~Set()
    {
        delete[] array;
    }
    
    Set(const Set& copiedSet)
    {
        this->setSize = copiedSet.setSize;
        this->maxSize = copiedSet.maxSize;
        
        delete[] this->array;
        this->array = new T[this->maxSize];
        
        for(int i = 0; i < copiedSet.setSize; i++)
            this->array[i] = copiedSet.array[i];
    }

    Set& operator=(const Set& copiedSet)
    {
        this->setSize = copiedSet.setSize;
        this->maxSize = copiedSet.maxSize;
        
        delete[] this->array;
        this->array = new T[this->maxSize];
        
        for(int i = 0; i < copiedSet.setSize; i++)
            this->array[i] = copiedSet.array[i];
        
        return *this;
    }
    
    template<class U>
    void insert(U&& x)
    {
        if(isMember(x))
            return;
            
        
    }
    
    bool isMember(T x)
    {
        return false;
    }
    
    void remove(T x)
    {
        if(setSize == 0)
            throw std::out_of_range ("underflow");
            
        
    }
    
    T pop()
    {
        if(setSize == 0)
            throw std::out_of_range ("underflow");
                    
        setSize--;
        return array[setSize];
    }
    
    int size()
    {
        return setSize;
    }
    
    Set intersection(const Set& S2)
    {
        Set<T> I;
        return I;
    }
    
    Set difference(const Set& S2)
    {
        Set<T> D;
        return D;
    }
    
    Set setUnion(const Set& S2)
    {
        Set<T> U;
        return U;
    }
    
    void printSet()
    {
        for(int i = 0; i < setSize; i++)
        {
            std::cerr << array[i] << " ";
        }
        std::cerr << std::endl << std::endl;
    }
    
private:
    int setSize;
    int maxSize;
    T *array;
};

#endif
