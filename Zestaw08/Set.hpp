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
    /* constructors, destructor */
    Set()
    {
        array = new T[8];
        maxSize = 8;
        setSize = 0;
    }

    Set(T *a, int m, int s)
    {
        array = a;
        maxSize = m;
        setSize = s;
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

    ~Set()
    {
        delete[] array;
    }
    

    /* member functions */
    template<class U>
    void insert(U&& x)
    {
        if(isMember(x))
            return;

        if(setSize == maxSize) // resize function
        {
            T *tempArray = new T[2 * maxSize];
            
            for(int i = 0; i < maxSize; i++)
                tempArray[i] = array[i];
               
            delete[] array;
            maxSize *= 2;
            array = tempArray;
        }
        
        T temp = std::forward<U>(x);
        for(int i = binsearchIndex(x); i < setSize + 1; i++)
            std::swap(temp, array[i]);
        setSize++;
    }
    
    bool isMember(T x)
    {
        for(int i = 0; i < setSize; i++)
        {
            if(array[i] == x)
                return true;
        }
        return false;
    }
    
    void remove(T x)
    {
        if(!isMember(x))
            return;

        if(setSize <= maxSize / 4)
        {
            T *tempArray = new T[maxSize / 2];
            
            for(int i = 0; i < setSize; i++)
                tempArray[i] = array[i];
               
            delete[] array;
            maxSize /= 2;
            array = tempArray;
        }

        setSize--;
        T temp = array[setSize];
        for(int i = setSize - 1; i >= 0; i--)
        {
            if(temp == x)
                break;  
            std::swap(temp, array[i]); 
        }
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
        int interMax = std::min(this->maxSize, S2.maxSize);
        int interSize = 0;
        T *interArr = new T[interMax];

        int index1 = 0, index2 = 0;

        while(index1 < this->setSize && index2 < S2.setSize)
        {
            if(this->array[index1] == S2.array[index2])
            {
                interArr[interSize] = this->array[index1];
                index1++;
                index2++;
                interSize++;
            }
            else if(this->array[index1] < S2.array[index2])
                index1++;
            else
                index2++;
        }

        if(interSize == 0)
            return Set();

        while(interSize <= interMax / 4)
        {
            T *tempArray = new T[interMax / 2];
            
            for(int i = 0; i < setSize; i++)
                tempArray[i] = interArr[i];
               
            delete[] interArr;
            interMax /= 2;
            interArr = tempArray;
        }
        
        return Set(interArr, interMax, interSize);
    }
    
    Set difference(const Set& S2)
    {
        int diffMax = this->maxSize;
        int diffSize = 0;
        T *diffArr = new T[diffMax];

        int index1 = 0, index2 = 0;

        while(index1 < this->setSize && index2 < S2.setSize)
        {
            if(this->array[index1] == S2.array[index2])
            {
                index1++;
                index2++;
            }
            else if(this->array[index1] < S2.array[index2])
            {
                diffArr[diffSize] = this->array[index1];
                diffSize++;
                index1++;
            }
            else
                index2++;
        }

        while(index1 < this->setSize)
        {
            diffArr[diffSize] = this->array[index1];
            diffSize++;
            index1++;
        }

        if(diffSize == 0)
            return Set();

        while(diffSize <= diffMax / 4)
        {
            T *tempArray = new T[diffMax / 2];
            
            for(int i = 0; i < setSize; i++)
                tempArray[i] = diffArr[i];
               
            delete[] diffArr;
            diffMax /= 2;
            diffArr = tempArray;
        }

        return Set(diffArr, diffMax, diffSize);
    }
    
    Set _union(const Set& S2)
    {
        int unionMax = 2 * std::max(this->maxSize, S2.maxSize);
        int unionSize = 0;
        T *unionArr = new T[unionMax];

        int index1 = 0, index2 = 0;

        while(index1 < this->setSize && index2 < S2.setSize)
        {
            if(this->array[index1] == S2.array[index2])
            {
                unionArr[unionSize] = this->array[index1];
                unionSize++;
                index1++;
                index2++;
            }
            else if(this->array[index1] < S2.array[index2])
            {
                unionArr[unionSize] = this->array[index1];
                unionSize++;
                index1++;
            }
            else
            {
                unionArr[unionSize] = S2.array[index2];
                unionSize++;
                index2++;
            }
        }

        while(index1 < this->setSize)
        {
            unionArr[unionSize] = this->array[index1];
            unionSize++;
            index1++;
        }

        while(index2 < S2.setSize)
        {
            unionArr[unionSize] = S2.array[index2];
            unionSize++;
            index2++;
        }

        if(unionSize == 0)
            return Set();

        while(unionSize <= unionMax / 4)
        {
            T *tempArray = new T[unionMax / 2];
            
            for(int i = 0; i < setSize; i++)
                tempArray[i] = unionArr[i];
               
            delete[] unionArr;
            unionMax /= 2;
            unionArr = tempArray;
        }

        return Set(unionArr, unionMax, unionSize);
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
    int binsearchIndex(T x)
    {
        int it, count, step;
        count = setSize;
        int first = 0;
     
        while(count > 0)
        {
            it = first; 
            step = count / 2; 
            it += step;
     
            if(x > array[it])
            {
                it++;
                first = it;
                count -= step + 1;
            } 
            else
                count = step;
        }
     
        return first;
    }

    void resizeDown(T *arr, int &m)
    {
        T *tempArray = new T[m / 2];
            
        for(int i = 0; i < setSize; i++)
            tempArray[i] = arr[i];
           
        delete[] arr;
        m /= 2;
        arr = tempArray;
    }

    int setSize;
    int maxSize;
    T *array;
};

#endif
