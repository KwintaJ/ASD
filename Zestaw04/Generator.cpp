//############################################//
//                                            //
//    Jan Kwinta                28.10.2022    //
//                                            //
//                                            //
//    Zestaw03: Lista I                       //
//    Plik: Generator.cpp                     //
//                                            //
//    Zadanie 2. Generator                    //
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
    int numOfOperations = 0;
    if(argc > 1)
        numOfOperations = atoi(argv[1]);
    std::cout << numOfOperations << std::endl;

    while(numOfOperations--)
    {
        int operationType = rand() % 6; // wylosowanie typu operacji:
                                        // 0 - push front
                                        // 1 - push back
                                        // 2 - pop front
                                        // 3 - pop back
                                        // 4 - replace
                                        // 5 - size
        switch(operationType)
        {
            case 0:
                {
                    std::cout << "F ";
                    int element = rand() % 1001; // wylosowanie elementu do wstawienia
                    std::cout << element << std::endl;
                }
                break;

            case 1:
                {
                    std::cout << "B ";
                    int element = rand() % 1001; // wylosowanie elementu do wstawienia
                    std::cout << element << std::endl;
                }
                break;

            case 2:
                std::cout << "f" << std::endl;
                break;

            case 3:
                std::cout << "b" << std::endl;
                break;

            case 4: 
                {
                    std::cout << "R ";
                    /* wylosowanie elementow do wstawienia */
                    int element1 = rand() % 1001; 
                    int element2 = rand() % 1001; 
                    std::cout << element1 << " " << element2 << std::endl;
                }
                break;

            case 5:
                std::cout << "S" << std::endl;
                break;
        }
    }
}
