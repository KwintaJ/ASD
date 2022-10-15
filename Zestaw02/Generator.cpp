//############################################//
//                                            //
//    Jan Kwinta                07.10.2022    //
//                                            //
//                                            //
//    Zestaw02: Kolejka                       //
//    Plik: Generator.cpp                     //
//                                            //
//    Generator                               //
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
    int numOfOperations = atoi(argv[1]);
    std::cout << numOfOperations << "\n";

    while(numOfOperations--)
    {
        int operationType = rand() % 3; // wylosowanie typu operacji:
                                        // 0 - push
                                        // 1 - pop
                                        // 2 - size
        switch(operationType)
        {
            case 0:
                {
                    std::cout << "A ";
                    int element = rand() % 1000001; // wylosowanie elementu do wstawienia
                    std::cout << element << "\n";
                }
                break;

            case 1:
                std::cout << "D\n";
                break;

            case 2:
                std::cout << "S\n";
                break;
        }
    }
}
