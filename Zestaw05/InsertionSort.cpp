//############################################//
//                                            //
//    Jan Kwinta                25.11.2022    //
//                                            //
//                                            //
//    Zestaw05: Proste algorytmy sortowania   //
//    Plik: InsertionSort.cpp                 //
//                                            //
//    Zadanie 1. Implementacja prostych       //
//               algorytmow sortowania;       //
//               Sortowanie przez wstawianie  //
//                                            //
//############################################//

#include <iostream>
#include <vector>

/* szablon funkcji sortujacej wektor v
   sortowanie przez wstawianie */
template <class T>
void sort(std::vector<T>& v)
{
    for(int i = 1; i < (int)v.size(); i++)
    {
        for(int j = i; j > 0 && v[j - 1] > v[j]; j--)
            std::swap(v[j - 1], v[j]);
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
        
    /* sortowanie wektora V */
    sort(V);
   
    /* wypisanie calej zawartosci wektora */
    for(const auto& i : V)
        std::cout << i << std::endl;
}
