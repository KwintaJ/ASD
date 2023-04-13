//############################################//
//                                            //
//    Jan Kwinta                13.04.2023    //
//                                            //
//                                            //
//    Zestaw10: Implementacja grafu           //
//                                            //
//    Plik: Graph.cpp                         //
//                                            //
//############################################//

#include "Graph.hpp"

#include <iostream>
#include <set>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    unsigned int s, n;
    std::cin >> s >> n;

    Graph Graf(s);

    /* ------ operacje ------ */
    
    char operation;
    int u, v;
    std::set<int> conn;
    while(n--)
    {
        std::cin >> operation;

        switch(operation)
        {
            case 'A':
                std::cin >> u >> v;
                Graf.addEdge(u, v);
                break;

            case 'R':
                std::cin >> u >> v;
                Graf.removeEdge(u, v);
                break;

            case 'H':
                std::cin >> u >> v;
                std::cout << "Pomiedzy wierzcholkami " << u << " i " << v;
                std::cout << (Graf.hasEdge(u, v) ? " jest krawedz." : " nie ma krawedzi.") << std::endl;
                break;

            case 'I':
                std::cin >> v;
                conn = Graf.inConnections(v);
                for(auto x : conn)
                    std::cout << x << ", ";
                std::cout << std::endl;
                conn.clear();
                break;

            case 'O':
                std::cin >> v;
                conn = Graf.outConnections(v);
                for(auto x : conn)
                    std::cout << x << ", ";
                std::cout << std::endl;
                conn.clear();
                break;

            case 'C':
                std::cin >> v;
                conn = Graf.allConnections(v);
                for(auto x : conn)
                    std::cout << x << ", ";
                std::cout << std::endl;
                conn.clear();
                break;
        }
    }

    /* ------ BFS ------ */

    std::vector<int> pathLens = Graf.BFS(6);
    for(auto x : pathLens)
        std::cout << x << "  ";
    std::cout << std::endl;

    
}
