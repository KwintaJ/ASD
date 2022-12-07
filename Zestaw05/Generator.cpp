//############################################//
//                                            //
//    Jan Kwinta                25.11.2022    //
//                                            //
//                                            //
//    Zestaw05: Proste algorytmy sortowania   //
//    Plik: Generator.cpp                     //
//                                            //
//    Zadanie 3. Generator                    //
//                                            //
//############################################//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    /* inicjalizacja generatora liczb pseudolosowych */
    time_t seed;
    srand(time(&seed));

    /* wypisanie liczby operacji podanej jako argument wywolania programu */
    int numOfOperations = 0, maxNum = 1;
    if(argc > 1)
        numOfOperations = atoi(argv[1]);
    if(argc > 2)
        maxNum = atoi(argv[2]);

    while(numOfOperations--)
    {
        std::cout << (rand() % maxNum) + 1 << "\n"; //wypisanie losowej liczby
    }
}
