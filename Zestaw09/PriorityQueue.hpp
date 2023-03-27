//############################################//
//                                            //
//    Jan Kwinta                26.03.2023    //
//                                            //
//                                            //
//    Zestaw08: Implementacja kolejki         //
//              priorytetowej                 //
//    Plik: PriorityQueue.hpp                 //
//                                            //
//############################################//

#include <stdexcept>
#include <algorithm>
#include <iostream>

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

template<class T>
class PriorityQueue
{    
public:
    struct QueueElem
    {
        QueueElem()
        {
            priority = -1;
        }
    
        template<class U>
        QueueElem(int p, U&& x)
        {
            priority = p;
            obj = std:forward<U>(x);
        }
        
        int priority;
        T obj;
    };
    
    PriorityQueue()
    {
        array = new QueueElem[8];
        maxSize = 8;
        queueSize = 0;
    }

    PriorityQueue(const PriorityQueue& copiedQueue)
    {
        this->queueSize = copiedQueue.queueSize;
        this->maxSize = copiedQueue.maxSize;
        
        delete[] this->array;
        this->array = new T[this->maxSize];
        
        for(int i = 0; i < copiedQueue.queueSize; i++)
            this->array[i] = copiedQueue.array[i];
    }

    PriorityQueue& operator=(const PriorityQueue& copiedQueue)
    {
        this->queueSize = copiedQueue.queueSize;
        this->maxSize = copiedQueue.maxSize;
        
        delete[] this->array;
        this->array = new T[this->maxSize];
        
        for(int i = 0; i < copiedQueue.queueSize; i++)
            this->array[i] = copiedQueue.array[i];
        
        return *this;
    }
    
    ~PriorityQueue()
    {
        delete[] array;
    }
    
    
    template<class U>
    void insert(int p, U&& x)
    {
        QueueElem newElement(p, std::forward<U>(x));
        
        if(queueSize == maxSize) // resize function
        {
            QueueElem *tempArray = new QueueElem[2 * maxSize];
            
            for(int i = 0; i < maxSize; i++)
                tempArray[i] = array[i];
               
            delete[] array;
            maxSize *= 2;
            array = tempArray;
        }
        
        int index = queueSize;
        array[index] = newElement;
        
        while(index > 0 && array[index].priority > array[parent(index)].priority)
        {
            std::swap(array[index], array[parent(index)]);
            index = parent(index);
        }
        
        queueSize++;
    }
    
    T max()
    {
        return array[0].obj;     
    }
    
    T extractMax()
    {      
        if(queueSize <= maxSize / 4)
        {
            QueueElem *tempArray = new QueueElem[maxSize / 2];
            
            for(int i = 0; i < queueSize; i++)
                tempArray[i] = array[i];
               
            delete[] array;
            maxSize /= 2;
            array = tempArray;
        }
        queueSize--;
        
        QueueElem toReturn = array[0];
        array[0] = array[queueSize];
        
        int index = 0;
        while(true)
        {
            if(leftChild(index) > queueSize)
                break;
            
            if(rightChild(index) > queueSize)
            {
                if(array[index].priority < array[leftChild(index)].priority)
                    std::swap(array[index], array[leftChild(index)]);
                break;
            }
            
            if(array[index].priority > array[leftChild(index)].priority && 
               array[index].priority > array[rightChild(index)].priority)
                break;
                
            if(array[leftChild(index)].priority >= array[rightChild(index)].priority)
            {
                std::swap(array[index], array[leftChild(index)]);
                index = leftChild(index);
            }
            else
            {
                std::swap(array[index], array[rightChild(index)]);
                index = rightChild(index);
            }
        }
               
        return toReturn.obj;
    }
    
    bool empty()
    {
        return queueSize == 0;
    }
    
    void printQueue()
    {
        for(int i = 0; i < queueSize; i++)
        {
            std::cerr << "(" << array[i].priority << ", " << array[i].obj << "),  ";
        }
        std::cerr << std::endl;
    }
        
private:
    int parent(int index)
    {
        return ((index + 1) / 2) - 1;
    }
    
    int leftChild(int index)
    {
        return ((index + 1) * 2) - 1;
    }
    
    int rightChild(int index)
    {
        return ((index + 1) * 2);
    }

    int queueSize;
    int maxSize;
    QueueElem *array;
};

#endif
