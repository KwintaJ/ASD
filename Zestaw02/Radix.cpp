//############################################//
//                                            //
//    Jan Kwinta                15.10.2022    //
//                                            //
//                                            //
//    Zestaw02: Kolejka                       //
//    Plik: Radix.cpp                         //
//                                            //
//    Zadanie 4. Sortowanie pozycyjne         //
//                                            //
//############################################//

#include "LinkedQueue.hpp"

#include <iostream>
#include <string>
#include <vector>

const int MAX_QUEUE_SIZE = 1000000;

/* funkcja wykonujaca sortowanie pozycyjne */
void radix(std::vector<int> &v)
{
    Queue<int, MAX_QUEUE_SIZE> Kolejka[10]; // tablica kolejek: w n-tej
                                            // kolejce znajduja sie liczby
                                            // majace cyfre n na pozycji i
                                            // przy i-tym obrocie petli

    int modDigitA = 10, modDigitB = 1; // dzielniki
    
    /* petla: sortowanie wedlug i-tej pozycji */ 
    for(int i = 0; i < 10; i++)
    {
        for(const auto num : v)
        {
            /* znalezienie cyfry na i-tej pozycji liczby num i 
               wlozenie num do odpowiedniej kolejki */
            int ithDigit = ((num % modDigitA) - (num % modDigitB)) / modDigitB;
            Kolejka[ithDigit].push(num);
        }

        v.clear(); // czyszczenie wektora

        /* do wektora wkladamy zawartosci wszystkich kolejek
           od 0-wej do 9-tej (od liczb ktore maja 0 na i-tej pozycji
           do liczb ktore maja 9 na i-tej pozycji) */
        for(int j = 0; j <= 9; j++)
        {
            while(!Kolejka[j].empty())
                v.push_back(Kolejka[j].pop());
        }

        /* zwiekszamy dzielniki o rzad wielkosci */
        modDigitA *= 10;
        modDigitB *= 10; 
    } 
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    std::vector<int> numbers; // wektor liczb wczytanych z wejscia

    /* wczytanie danych */
    int input;
    while(std::cin >> input)
        numbers.push_back(input);

    /* wywolanie funkcji sortujacej */
    radix(numbers);

    /* wypisanie danych */
    for(const auto &x : numbers)
        std::cout << x << "\n";
}
