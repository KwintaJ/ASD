//############################################//
//                                            //
//    Jan Kwinta                03.06.2023    //
//                                            //
//                                            //
//    Zestaw11: Zadanie Sejfy                 //
//                                            //
//    Plik: Sejfy.cpp                         //
//                                            //
//############################################//

#include <iostream>

#include "Vector.hpp"
#include "LinkedQueue.hpp"

struct safE 
{
    int id;
    Vector<int> keysInside;
    bool opened;
    bool visited;

    safE()
    {
        id = -1;
        opened = false;
        visited = false;
    }

    safE(int x)
    {
        id = x;
        opened = false;
        visited = false;
    }
};

bool crackOpenASafe(Vector<safE> &bank, int v)
{
    bool newCracking = true;
    
    Queue<int> accessibleSafes;
    accessibleSafes.push(v);
    int currentSafe;
    while(!accessibleSafes.empty())
    {
        currentSafe = accessibleSafes.front();
        accessibleSafes.pop();

        bank[currentSafe].visited = true;
        for(auto u : bank[currentSafe].keysInside)
        {
            if(bank[u].opened)
                newCracking = false;
            if(!bank[u].visited)
                accessibleSafes.push(u);
        }
    }

    accessibleSafes.push(v);
    while(!accessibleSafes.empty())
    {
        currentSafe = accessibleSafes.front();
        accessibleSafes.pop();

        bank[currentSafe].opened = true;
        for(auto u : bank[currentSafe].keysInside)
        {
            if(!bank[u].opened)
                accessibleSafes.push(u);
        }
    }
    
    return newCracking;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    /* ======= input ======= */
    int numOfSafes;
    std::cin >> numOfSafes;
    Vector<safE> theBank;

    for(int i = 0; i < numOfSafes; i++)
    {
        theBank.push_back(safE(i));        
    }

    for(int i = 0; i < numOfSafes; i++)
    {
        int keyToIthSafe;
        std::cin >> keyToIthSafe;
        keyToIthSafe--;
        theBank[keyToIthSafe].keysInside.push_back(i);
    }

    /* ======= the algorithm ======= */
    int crackedSafesCounter = 0;

    for(int i = 0; i < numOfSafes; i++)
    {
        if(!theBank[i].opened)
        {
            std::cerr << "starting BFS on " << i << std::endl;
            if(crackOpenASafe(theBank, i))
            {
                std::cerr << "was a new crack" << std::endl;
                crackedSafesCounter++;
            }
            else
                std::cerr << "was not a new crack" << std::endl;
        }
    }

    /* ======= output ======= */
    std::cout << crackedSafesCounter << std::endl;
}
