//############################################//
//                                            //
//    Jan Kwinta                04.11.2022    //
//                                            //
//                                            //
//    Zestaw04: Lista II                      //
//    Plik: ArrayList.hpp                     //
//                                            //
//    Zadanie 1. Implementacja tablicowa      //
//               listy                        //
//                                            //
//############################################//


#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>
#include <memory>


#ifndef ARRAYLIST
#define ARRAYLIST

template<class T>
class ArrayList
{
public:
    struct Iterator
    {
        T* pos;

        Iterator(T* p): pos{p}
        {
        }

        T &operator*() const
        {
            return *pos;
        }
        T *operator->() const
        {
            return &pos;
        }
        bool operator==(const Iterator &X)
        {
           return this->pos == X.pos;
        }
        bool operator!=(const Iterator &Y)
        {
            return !(*this == Y);
        }
        Iterator operator++()
        {
            pos++;
            return *this;
        }
        Iterator operator--()
        {
            pos--;
            return *this;
        }
    };

    /* constructors */
    ArrayList()
    {
        listSize = 0;
    }

    ~ArrayList()
    {
    }

    ArrayList(const ArrayList& copiedList)
    {
        this->listSize = 0;
        for(int i = 0; i < copiedList.listSize; i++)
        {
            this->push_back(copiedList.array[i]);
        }
    }

    ArrayList& operator=(const ArrayList& copiedList)
    {
        this->clear();
        for(int i = 0; i < copiedList.listSize; i++)
        {
            this->push_back(copiedList.array[i]);
        }
        return *this;
    }

    ArrayList(ArrayList&& movedList)
    {
        listSize = std::move(movedList.listSize);
        for(int i = 0; i < movedList.listSize; i++)
        {
            array[i] = std::move(movedList.array[i]);
        }
    }

    ArrayList& operator=(ArrayList&& movedList)
    {
        listSize = std::move(movedList.listSize);
        for(int i = 0; i < movedList.listSize; i++)
        {
            array[i] = std::move(movedList.array[i]);
        }
        return *this;
    }

    /* methods */
    int size() const
    {
        return listSize;
    }

    bool empty()
    {
        return listSize == 0;
    }

    template<class U>
    Iterator insert(Iterator it, U&& x)
    {
        listSize++;
        T temp = std::forward<U>(x);

        for(Iterator it2 = it; it2 != end(); ++it2)
        {

            std::swap(*it2, temp);
        }

        return it;
        
    }

    Iterator erase(Iterator it)
    {
        listSize--;
        
        for(Iterator it2 = it; it2 != end(); ++it2)
        {
            Iterator it3 = it2;
            ++it3;
            std::swap(*it2, *it3);
        }

        return it;
        
    }

    int remove(const T& x)
    {
        int counter = 0;
        Iterator it = begin();

        while(it != end())
        {
            if(*it == x)
            {
                counter++;
                it = erase(it);
            }
            else
                it++;
        }

        return counter;
    }

    void clear()
    {
        Iterator it = end();
        --it;
        while(!empty())
        {
            erase(it);
            it = end();
            --it;
        }
    }

    Iterator find(const T& x)
    {
        for(Iterator it = begin(); it != end(); ++it)
        {
            if(*it == x)
                return it;
        }
        return end();
    }

    template<class U>
    bool replace(const T& x, U&& y)
    {
        Iterator firstOccurence = find(x);

        if(firstOccurence != end())
        {
            insert(erase(firstOccurence), std::forward<U>(y));
            return true;
        }
        return false;
    }
    
    template<class U>
    void push_front(U&& x)
    {
        if(listSize == maxSize)
            throw std::out_of_range ("overflow");

        insert(begin(), std::forward<U>(x));
    }
    
    T pop_front()
    {
        if(listSize == 0)
            throw std::out_of_range ("underflow");

        T val = array[0];
        erase(begin());
        return val;
    }

    template<class U>
    void push_back(U&& x)
    {
        if(listSize == maxSize)
            throw std::out_of_range ("overflow");
        
        insert(end(), std::forward<U>(x));
    }

    T pop_back()
    {
        if(listSize == 0)
            throw std::out_of_range ("underflow");

        T val = array[listSize - 1];
        erase((--end()));
        return val;
    }

    Iterator begin()
    { 
        return &array[0];
    }

    Iterator end()
    {
        return &array[listSize];
    }

private:
    T array[1000];
    int listSize;
    const int maxSize = 1000;
};

#endif