//############################################//
//                                            //
//    Jan Kwinta                28.10.2022    //
//                                            //
//                                            //
//    Zestaw03: Lista I                       //
//    Plik: LinkedList.hpp                    //
//                                            //
//    Zadanie 1. Implementacja wskaznikowa    //
//               dwukierunkowa listy          //
//                                            //
//############################################//

#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <iostream>

template<class T>
class LinkedList
{
public:
    struct Node
    {
        T x;
        Node* prev;
        Node* next;
        
        Node(Node* p = nullptr, Node* n = nullptr): prev{p}, next{n}
        {
        }
        
        Node(T& val, Node* p, Node* n): x{val}, prev{p}, next{n}
        {
        }
    };
    
    struct Iterator
    {
        Node *ptr;
        
        Iterator(Node* p = nullptr): ptr{p}
        {
        }
        
        T &operator*()
        {
            return ptr->x;
        }
        
        T *operator->()
        {
            return &(ptr->x);
        }
        
        bool operator==(const Iterator &X)
        {
            return this->ptr == X.ptr;
        }
        
        bool operator!=(const Iterator &X)
        {
            return !(this == X);
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
    };
    
    LinkedList()
    {
        size_ = 0;
        guard = Node();
    }
    
    Iterator erase(Iterator position)
    {
        if(position == nullptr)
            return nullptr;

        if(position->prev != nullptr)
            position->prev->next = position->next;

        if(position->next != nullptr)
            position->next->prev = position->prev;

        if(position == guard.next)
            guard.next = position->next;

        if(position == guard.prev)
            guard.prev = position->prev;
    }
    
    template<class U>
    void push_front(U&& x)
    {
        if(size_ == 0)
        {
            Node* newItem = new Node(std::forward(x), *guard, *guard); 
            guard.prev = newItem;
            guard.next = newItem;
        }
        else
        {
            Node* newItem = new Node(std::forward(x), *guard, guard.next);
            guard.next = newItem;
        }
        size_++;
    }
    
    T pop_front()
    {
        Node* toPop = guard.next
        T toRet = toPop->x;
        
        erase(toPop);
        
        delete toPop;
        size_--;  
        return toRet;
    }
    
    template<class U>
    void push_back(U&& x)
    {
        if(size_ == 0)
        {
            Node* newItem = new Node(std::forward(x), *guard, *guard); 
            guard.prev = newItem;
            guard.next = newItem;
        }
        else
        {
            Node* newItem = new Node(std::forward(x), guard.prev, *guard);
            guard.prev = newItem;
        }
        size_++;
    }
    
    T pop_back()
    {
    
    }
    
    Iterator find(const T& x)
    {
        
    }
    
    template<class U>
    Iterator insert(Iterator it, U&& x)
    {
    
    }
    
    int remove(const T& x)
    {
        int counter = 0;
        
        
        return counter;
    }
    
    int size()
    {
        return size_;
    }
    
    bool empty()
    {
        return (size_ == 0);
    }
    
    void clear()
    {
    
    }
    
    Iterator begin()
    {
        return Iterator{guard->next};
    }
    
    Iterator end()
    {
        return Iterator{guard->prev};
    }
    
      
private:
    Node guard;
    int size_;
};

#endif
