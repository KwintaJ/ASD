//############################################//
//                                            //
//    Jan Kwinta                28.12.2022    //
//                                            //
//                                            //
//    Zestaw07: Slownik                       //
//    Plik: Dict.cpp                          //
//                                            //
//    Zadanie 1. Slownik                      //
//                                            //
//############################################//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>

#include "LinkedList.hpp"

const unsigned int NUM_OF_BUCKETS = 16;

int powerModulo(long long a, unsigned int b, int p)
{
    int result = 1;
    a %= p; 
  
    if(a == 0)
        return 0;
 
    while(b > 0)
    {
        if(b % 2 == 1)
            result = (result * a) % p;
 
        b /= 2;
        a = (a * a) % p;
    }

    return result;
}

unsigned int hash(const std::string& k)
{
    unsigned int index = 0;
    int n = k.length();

    for(int i = 0; i < n; i++)
        index += powerModulo((int)k[i], n - i, NUM_OF_BUCKETS);

    return index %= NUM_OF_BUCKETS;
}

template<class K, class V>
class Dict
{
using Pair = std::pair<K, V>;
public:
    Dict()
    {
        dictSize = 0;
    }

    void clear()
    {
        for(unsigned int i = 0; i < NUM_OF_BUCKETS; i++)
            hashList[i].clear();
    }

    bool insert(const Pair& p)
    {
        bool notExistsAlready = true;
        if(find(p.first))
        {
            notExistsAlready = false;
            erase(p.first);
            // return false;
        }

        unsigned int hashIndex = hash(p.first);
        hashList[hashIndex].push_front(p);
        dictSize++;
        return notExistsAlready;
    }

    bool find(const K& k)
    {
        unsigned int hashIndex = hash(k);
        return hashList[hashIndex].findKey(k);
    }

    V& operator[](const K& k)
    {
        if(!find(k))
        {
            Pair newPair{k, NULL};
            insert(newPair);
        }
        
        unsigned int hashIndex = hash(k);
        return (hashList[hashIndex].findKeyIterator(k))->second;
    }

    bool erase(const K& k)
    {
        if(!find(k))
            return false;

        unsigned int hashIndex = hash(k);
        hashList[hashIndex].erase(hashList[hashIndex].findKeyIterator(k));
        return true;
    }

    int size()
    {
        return dictSize;
    }

    bool empty()
    {
        return dictSize == 0;
    }

    void buckets()
    {
        int minimal = 20000000;
        int maximal = -1;

        for(unsigned int i = 0; i < NUM_OF_BUCKETS; i++)
        {
            minimal = std::min(hashList[i].size(), minimal);
            maximal = std::max(hashList[i].size(), maximal);
        }

        std::cout << "# " << dictSize << " "
                  << NUM_OF_BUCKETS << " " << minimal << " "
                  << maximal << std::endl;
    }

private:
    int dictSize;
    LinkedList<Pair> hashList[NUM_OF_BUCKETS];
};

std::ifstream in;

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    if(argc < 2)
        return 0;

    std::string file = argv[1];

    in.open(file);
    if(!in.good())
        return 0;

    Dict<std::string, std::string> Slownik;

    std::string one, two;  
    while(in >> one >> two)
    {
        std::pair<std::string, std::string> pairOfWords(one, two);
        Slownik.insert(pairOfWords);
    }

    in.close();

    // Slownik.buckets();

    std::string word;
    while(std::cin >> word)
    {
        if(!Slownik.find(word))
            std::cout << "-" << std::endl;
        else
            std::cout << Slownik[word] << std::endl;
    }
}