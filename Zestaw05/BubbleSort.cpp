//############################################//
//                                            //
//    Jan Kwinta                25.11.2022    //
//                                            //
//                                            //
//    Zestaw05: Proste algorytmy sortowania   //
//    Plik: BubbleSort.cpp                    //
//                                            //
//    Zadanie 1. Implementacja prostych       //
//               algorytmow sortowania;       //
//               Sortowanie babelkowe         //
//                                            //
//############################################//

#include <iostream>
#include <vector>
#include <chrono>

/* szablon funkcji sortujacej wektor v
   sortowanie babelkowe */
template <class T>
void sort(std::vector<T>& v)
{
    for(int i = 0; i < (int)v.size(); i++)
    {
        for(int j = i + 1; j < (int)v.size(); j++)
        {
            if(v[i] > v[j])
                std::swap(v[i], v[j]);
        }
    }
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    std::vector<int> V; // stworzenie wektora intow V
    
    /* wczytanie wszystkich liczb na standardowym wejsciu do V */
    int x;
    while(std::cin >> x)
        V.push_back(x);
        
    /* pomiar czasu */
    auto start = std::chrono::high_resolution_clock::now();
        
    /* sortowanie wektora V */
    sort(V);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
   
    /* wypisanie calej zawartosci wektora */
    for(const auto& i : V)
        std::cout << i << std::endl;
}
