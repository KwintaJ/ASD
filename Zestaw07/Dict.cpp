//############################################//
//                                            //
//    Jan Kwinta                09.12.2022    //
//                                            //
//                                            //
//    Zestaw07: Slownik                       //
//    Plik: Dict.cpp                          //
//                                            //
//    Zadanie 1. Slownik                      //
//                                            //
//############################################//

#include <iostream>
#include <string>
#include <fstream>

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
    }

    bool insert(const Pair& p)
    {
        return false;
    }

    bool find(const K& k)
    {
        return false;
    }

    V& operator[](const K& k)
    {
        return NULL;
    }

    bool erase(const K& k)
    {
        return false;
    }

    int size()
    {
        return dictSize;
    }

    bool empty()
    {
        return dictSize == 0;
    }

    void buckets() // info
    {
    }

private:
    int dictSize;

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


}