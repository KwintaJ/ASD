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
    bool sorted;

    safE()
    {
        id = -1;
        opened = false;
        sorted = false;
    }

    safE(int x)
    {
        id = x;
        opened = false;
        sorted = false;
    }
};

void tSort(Vector<safE> &bank, int v, Vector<safE> &bankSorted)
{
    bank[v].sorted = true;
    for(auto u : bank[v].keysInside)
    {
        if(!bank[u].sorted)
            tSort(bank, u, bankSorted);
    }
    bankSorted.push_back(bank[v]);
}

void sortTopologically(Vector<safE> &bank, Vector<safE> &bankSorted)
{
    Vector<safE> bankSortedReversed;
    for(int i = 0; i < bank.size(); i++)
    {
        if(!bank[i].sorted)
            tSort(bank, i, bankSortedReversed);
    }

    for(int i = bankSortedReversed.size() - 1; i >= 0; i--)
        bankSorted.push_back(bankSortedReversed[i]);
}

void crackOpenASafe(Vector<safE> &bank, int v)
{
    // std::cerr << "  " << bank[v].id << std::endl;
    Queue<int> accessibleSafes;
    accessibleSafes.push(v);
    int currentSafe;
    while(!accessibleSafes.empty())
    {
        currentSafe = accessibleSafes.front();
        accessibleSafes.pop();

        bank[currentSafe].opened = true;
        for(auto u : bank[currentSafe].keysInside)
        {
            // std::cerr << "    " << bank[u].id << std::endl;     
            if(!bank[u].opened)
                accessibleSafes.push(u);
        }
    }
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    /* ======= input ======= */
    int numOfSafes;
    std::cin >> numOfSafes;
    Vector<safE> theBank;
    Vector<safE> theBankSorted;

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
    
    sortTopologically(theBank, theBankSorted);
    // for(auto s : theBankSorted)
    //     std::cerr << s.id << " ";
    // std::cerr << std::endl;

    for(int i = 0; i < numOfSafes; i++)
    {
        int safeToOpen = theBankSorted[i].id;
        if(!theBank[safeToOpen].opened)
        {
            // std::cerr << "cracking " << safeToOpen << std::endl;
            crackOpenASafe(theBank, theBankSorted[i].id);
            crackedSafesCounter++;
        }
    }

    /* ======= output ======= */
    std::cout << crackedSafesCounter << std::endl;
}
