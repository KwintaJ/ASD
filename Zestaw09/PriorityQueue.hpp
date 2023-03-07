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
struct QueueElem
{
    int priority;
    T val;
};

template<class T>
class PriorityQueue
{    
public:
    PriorityQueue()
    {
        
    }

    ~PriorityQueue()
    {
        
    }
    
    template<class U>
    void insert(U&& x, int p)
    {
        
    }
    
    
private:
    
};

#endif
