//############################################//
//                                            //
//    Jan Kwinta                04.11.2022    //
//                                            //
//                                            //
//    Zestaw04: Lista II                      //
//    Plik: CursorList.hpp                    //
//                                            //
//    Zadanie 1. Implementacja kursorowa      //
//               listy                        //
//                                            //
//############################################//


#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>


#ifndef CURSORLIST
#define CURSORLIST

template<class T>
class CursorList
{
public:
    struct Node
    {
        Node(): data{NULL}, indexNext{-1}, next{nullptr}
        {
        }

        T data;
        int indexNext;
        Node* next;
    };

    struct Iterator
    {
        int index;
        Node* ptr;
        
        Iterator(int i, Node* p): index{i}, ptr{p}
        {
        }

        T &operator*()
        {
            return ptr->data;
        }
        T *operator->()
        {
            return &(ptr->data);
        }
        bool operator==(const Iterator &X)
        {
            return this->index == X.index;
        }
        bool operator!=(const Iterator &Y)
        {
            return !(*this == Y);
        }
        Iterator operator++()
        {
            ptr = ptr->next;
            index = ptr->indexNext;
            return *this;
        }
    };

    /* constructors */
    CursorList()
    {
        listSize = 0;
        spare = 0;
        head = -1;
        tail = -1;

        for(int i = 0; i < maxSize; i++)
        {
            array[i].indexNext = i + 1;
            array[i].next = &array[i + 1];
        }
    }

    ~CursorList()
    {
    
    }

    CursorList(const CursorList& copiedList)
    {
        
    }

    CursorList& operator=(const CursorList& copiedList)
    {

    }

    CursorList(CursorList&& movedList)
    {

    }

    CursorList& operator=(CursorList&& movedList)
    {

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

        int xsIndex = spare;

        array[xsIndex].data = std::forward<U>(x);
        spare = array[xsIndex].indexNext;

        if(listSize == 1)
        {
            array[xsIndex].indexNext = spare;
            array[xsIndex].next = &array[spare];
            head = 0;
            tail = 0;
            return begin();
        }
        if(it == begin())
        {
            array[xsIndex].indexNext = head;
            array[xsIndex].next = &array[head];
            head = xsIndex;
            return it;
        }
        if(it == end())
        {
            array[tail].indexNext = xsIndex;
            array[tail].next = &array[xsIndex];
            tail = xsIndex;
            return Iterator{xsIndex, &array[xsIndex]};
        }

        for(Iterator it2 = begin(); it2 != end(); ++it2)
        {
            if(Iterator{it2.ptr->indexNext, it2.ptr->next} == it)
            {
                int index2 = it2.index;
                array[xsIndex].indexNext = array[index2].indexNext;
                array[xsIndex].next = array[xsIndex].next;

                array[index2].indexNext = index2;
                array[index2].next = &array[xsIndex];

                return it;
            }
        }
 
        return it;        
    }

    Iterator erase(Iterator it)
    {
        listSize--;
        Iterator itToSpare = end();

        if(listSize == 0)
        {
            spare = 0;
            array[spare].indexNext = itToSpare.index;
            array[spare].next = itToSpare.ptr;
            head = -1;
            tail = -1;
            return end();
        }
        if(it == begin())
        {
            spare = head;
            head = array[head].indexNext;
            array[spare].indexNext = itToSpare.index;
            array[spare].next = itToSpare.ptr;
            return it;
        }

        for(Iterator it2 = begin(); it2 != end(); ++it2)
        {
            if(Iterator{it2.ptr->indexNext, it2.ptr->next} == it)
            {
                int index2 = it2.index;
                spare = array[index2].indexNext;
                array[spare].indexNext = itToSpare.index;
                array[spare].next = itToSpare.ptr;

                array[index2].next = array[array[index2].indexNext].next;
                array[index2].indexNext = array[array[index2].indexNext].indexNext;
                if(it == Iterator{tail, &array[tail]})
                {
                    tail = index2;
                }

                return ++it2;
            }
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
        for(Iterator it = end(); listSize > 0; --it)
        {
            erase(it);
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

        T val = array[head].data;
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

        T val = array[tail].data;
        erase(Iterator{tail, &array[tail]});
        return val;
    }

    Iterator begin()
    {
        if(listSize == 0)
            return end();
        return Iterator{head, &array[head]};
    }

    Iterator end()
    {
        return Iterator{spare, &array[spare]};
    }

private:
    Node array[1000];
    int head;
    int tail;
    int spare;
    int listSize;
    const int maxSize = 3;
};

#endif