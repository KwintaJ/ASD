//############################################//
//                                            //
//    Jan Kwinta                28.12.2022    //
//                                            //
//                                            //
//    Zestaw07: Slownik                       //
//    Plik: LinkedList.hpp                    //
//                                            //
//    Zadanie 1. Slownik                      //
//               Zmodyfikowany kod listy      //
//               wskaznikowej                 //
//                                            //
//############################################//


#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>

#ifndef LINKEDLIST
#define LINKEDLIST

template<class T>
class LinkedList
{
public:
    struct Node
    {
        Node()
        {
        }

        Node(const T &e): data{e}
        {
        }

        Node(Node *n, Node *p)
        {
            next = n;
            prev = p;
        }

        T data;
        Node *next;
        Node *prev;
    };

    struct Iterator
    {
        Node *ptr;

        Iterator(Node *p = nullptr): ptr{p}
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
            return this->ptr == X.ptr;
        }
        bool operator!=(const Iterator &Y)
        {
            return !(*this == Y);
        }
        Iterator operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        Iterator operator--()
        {
            ptr = ptr->prev;
            return *this;
        }
        Iterator operator++(int)
        {
            Node *help = ptr;
            ptr = ptr->next;
            return Iterator{help};
        }
        Iterator operator--(int)
        {
            Node *help = ptr;
            ptr = ptr->prev;
            return Iterator{help};
        }
    };

    /* constructors */
    LinkedList()
    {
        listSize = 0;
        maxSize = 100000;
        guard = Node(&guard, &guard);
    }

    ~LinkedList()
    {
        Iterator it = begin();

        while(listSize > 0)
            it = erase(it);
    }

    /* methods */
    int size() const
    {
        return listSize;
    }

    template<class U>
    Iterator insert(Iterator it, U&& x)
    {
        listSize++;
        Node *n = new Node(std::forward<U>(x));

        if(listSize == 1)
        {
            guard.next = n;
            guard.prev = n;
            n->next = &guard;
            n->prev = &guard;
            return Iterator{n}; 
        }
        
        n->next = it.ptr;
        n->prev = it.ptr->prev;
        it.ptr->prev = n;
        n->prev->next = n;
        
        return Iterator{n};        
    }

    Iterator erase(Iterator it)
    {
        listSize--;
        Iterator toReturn = Iterator{it.ptr->next};

        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;

        delete it.ptr;

        return toReturn;
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
        Iterator it = begin();

        while(listSize > 0)
            it = erase(it);
    }

    Iterator find(const T& x)
    {
        Iterator it = begin();

        while(it != end())
        {
            if(*it == x)
                return it;
            it++;
        }

        return it;
    }

    bool findKey(const std::string& x)
    {
        Iterator it = begin();

        while(it != end())
        {
            if(it->first == x)
                return true;
            it++;
        }

        return false;
    }

    Iterator findKeyIterator(const std::string& x)
    {
        Iterator it = begin();

        while(it != end())
        {
            if(it->first == x)
                return it;
            it++;
        }

        return it;
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

        T val = guard.next->data;
        erase(Iterator{guard.next});
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

        T val = guard.prev->data;
        erase(Iterator{guard.prev});
        return val;
    }

    Iterator begin()
    { 
        return Iterator{guard.next};
    }

    Iterator end()
    {
        return Iterator{&guard};
    }

private:
    Node guard;
    int listSize;
    int maxSize;
};

#endif