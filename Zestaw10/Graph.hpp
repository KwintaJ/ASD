//############################################//
//                                            //
//    Jan Kwinta                13.04.2023    //
//                                            //
//                                            //
//    Zestaw10: Implementacja grafu           //
//                                            //
//    Plik: Graph.hpp                         //
//                                            //
//############################################//

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>

#ifndef GRAPH
#define GRAPH


class Graph
{    
public:
    Graph(unsigned int numVert)
    {
        graphSize = numVert;
        array = std::vector<std::set<int>>(numVert);
    }

    void addEdge(int i, int j)
    {
        array[i].insert(j);
    }

    void removeEdge(int i, int j)
    {
        auto jthIndex = array[i].find(j);
        if(jthIndex != array[i].end())
            array[i].erase(jthIndex);
    }

    bool hasEdge(int i, int j)
    {
        return array[i].find(j) != array[i].end();
    }

    std::set<int> inConnections(int i)
    {
        std::set<int> S;
        
        int k = 0;
        for(auto C : array)
        {
            if(C.find(i) != C.end())
            {
                S.insert(k);
            }
            k++;
        }

        return S;
    }

    std::set<int> outConnections(int i)
    {
        return array[i];
    }

    std::set<int> allConnections(int i)
    {
        std::set<int> S(array[i]);

        int k = 0;
        for(auto C : array)
        {
            if(C.find(i) != C.end())
            {
                S.insert(k);
            }
            k++;
        }

        return S;
    }

    void print()
    {
        int k = 0;
        for(auto C : array)
        {
            std::cout << k << ":" << std::endl;
            for(auto x : C)
                std::cout << "    " << x << ", ";
            std::cout << std::endl << std::endl;
            k++;
        }
    }

    std::vector<int> BFS(int v)
    {
        std::vector<int> Lens(graphSize, -1);
        Lens[v] = 0;

        std::queue<int> Q;
        int currentV = v;
        do{
            for(auto u : array[currentV])
            {
                if(Lens[u] == -1)
                {
                    Q.push(u);
                    Lens[u] = Lens[currentV] + 1;
                }
            }
            currentV = Q.front();
            Q.pop();
        }
        while(!Q.empty());

        return Lens;
    }
    
private:
    int graphSize;
    std::vector<std::set<int>> array;
};

#endif
