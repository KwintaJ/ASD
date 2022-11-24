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
        T data;
        int next;
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
            array[i].next = i + 1;
        }
    }

    ~CursorList()
    {
    }

    CursorList(const CursorList& copiedList)
    {
        this->listSize = 0;
        this->spare = 0;
        this->head = -1;
        this->tail = -1;
        for(int i = 0; i < maxSize; i++)
        {
            this->array[i].next = i + 1;
        }

        for(int i = 0; i < copiedList.listSize; i++)
        {
            this->push_back(copiedList.array[i].data);
        }
    }

    CursorList& operator=(const CursorList& copiedList)
    {
        this->clear();
        for(int i = 0; i < copiedList.listSize; i++)
        {
            this->push_back(copiedList.array[i].data);
        }
        return *this;
    }

    CursorList(CursorList&& movedList)
    {
        listSize = std::move(movedList.listSize);
        spare = std::move(movedList.spare);
        head = std::move(movedList.head);
        tail = std::move(movedList.tail);
        for(int i = 0; i < maxSize; i++)
        {
            array[i].data = std::move(movedList.array[i].data);
            array[i].next = std::move(movedList.array[i].next);
        }
    }

    CursorList& operator=(CursorList&& movedList)
    {
        listSize = std::move(movedList.listSize);
        spare = std::move(movedList.spare);
        head = std::move(movedList.head);
        tail = std::move(movedList.tail);
        for(int i = 0; i < maxSize; i++)
        {
            array[i].data = std::move(movedList.array[i].data);
            array[i].next = std::move(movedList.array[i].next);
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
    void insert(int i, U&& x)
    {
        listSize++;
        
        int xsIndex = spare;
        array[xsIndex].data = std::forward<U>(x);

        if(listSize == 1)
        {
            head = xsIndex;
            tail = xsIndex;
            spare = array[spare].next;
            array[tail].next = spare;
            return;
        }

        if(i == head)
        {
            spare = array[spare].next;

            array[xsIndex].next = head;
            head = xsIndex;

            array[tail].next = spare;

            return;
        }

        if(i == spare)
        {
            array[tail].next = xsIndex;
            tail = xsIndex;

            spare = array[spare].next;
            array[xsIndex].next = spare;

            array[tail].next = spare;

            return;
        }

        spare = array[spare].next;

        for(int j = head; j != spare; )
        {
            if(array[j].next == i)
            {
                array[j].next = xsIndex;
                array[xsIndex].next = i;
                array[tail].next = spare;

                return;
            }

            j = array[j].next;
        }  

        return;
    }

    int erase(int i)
    {
        listSize--;   

        if(listSize == 0)
        {
            array[i].next = spare;
            spare = i;
            head = -1;
            tail = -1;
            return spare;
        }

        if(i == head)
        {
            head = array[i].next;
            array[i].next = spare;
            spare = i;

            array[tail].next = spare;

            return head;
        }

        if(i == tail)
        {
            for(int j = head; j != spare; )
            {
                if(array[j].next == i)
                {   
                    array[i].next = spare;
                    spare = i;

                    array[j].next = spare;
                    tail = j;

                    return spare;
                }

                j = array[j].next;
            } 

            return tail;            
        }

        for(int j = head; j != spare; )
        {
            if(array[j].next == i)
            {
                array[j].next = array[i].next;
                array[i].next = spare;
                spare = i;
                return array[j].next;
            }

            j = array[j].next;
        }  

        return -1;
    }

    int remove(const T& x)
    {
        int counter = 0;
        int i = head;

        while(i != spare)
        {
            if(array[i].data = x)
            {
                counter++;
                erase(i);
            }
            
            i = array[i].next;
        }

        return counter;
    }

    void clear()
    {
        for(int i = head; listSize > 0; i = head)
        {
            erase(i);
        }
    }

    int find(const T& x)
    {
        for(int i = head; i != spare; )
        {
            if(array[i].data == x)
                return i;

            i = array[i].next;
        }
        return -1;
    }

    template<class U>
    bool replace(const T& x, U&& y)
    {
        int firstOccurence = find(x);

        if(firstOccurence != -1)
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

        insert(head, std::forward<U>(x));
    }
    
    T pop_front()
    {
        if(listSize == 0)
            throw std::out_of_range ("underflow");

        T val = array[head].data;
        erase(head);
        return val;
    }

    template<class U>
    void push_back(U&& x)
    {
        if(listSize == maxSize)
            throw std::out_of_range ("overflow");
        
        insert(spare, std::forward<U>(x));
    }

    T pop_back()
    {
        if(listSize == 0)
            throw std::out_of_range ("underflow");

        T val = array[tail].data;
        erase(tail);
        return val;
    }

private:
    Node array[1000];
    int head;
    int tail;
    int spare;
    int listSize;
    const int maxSize = 1000;
};

#endif