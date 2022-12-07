//############################################//
//                                            //
//    Jan Kwinta                25.11.2022    //
//                                            //
//                                            //
//    Zestaw05: Proste algorytmy sortowania   //
//    Plik: SelectionSort.cpp                 //
//                                            //
//    Zadanie 1. Implementacja prostych       //
//               algorytmow sortowania;       //
//               Sortowanie przez wybieranie  //
//                                            //
//############################################//

#include <iostream>
#include <vector>
#include <chrono>

#define MAXIMAL_VAL 200000000

/* szablon funkcji sortujacej wektor v
   sortowanie przez wybieranie */
template <class T>
void sort(std::vector<T>& v)
{
    for(int i = 0; i < (int)v.size(); i++)
    {
        int ithMinIndex = i;
        for(int j = i; j < (int)v.size(); j++)
        {
            if(v[j] < v[ithMinIndex])
                ithMinIndex = j;
        }
        std::swap(v[i], v[ithMinIndex]);
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
    std::cerr << elapsed.count() << ", ";
   
    /* wypisanie calej zawartosci wektora */
    for(const auto& i : V)
        std::cout << i << std::endl;
}
