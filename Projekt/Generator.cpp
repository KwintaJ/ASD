//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: Generator.cpp                     //
//                                            //
//    Program do generowania danych           //
//    wejsciowych                             //
//                                            //
//############################################//

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <set>

void writeTest(int modulo, std::string fileName)
{
    int w = (rand() % std::min(modulo, 10000)) + 3;
    int h = (rand() % std::min(modulo, 10000)) + 3;
    int n = (rand() % std::min(modulo, 15000)) + 10;

    std::ofstream fileToWrite(fileName);

    fileToWrite << w << " " << h << " " << n << std::endl;

    std::set<std::pair<int, int>> S;
    for(int i = 0; i < n; i++)
    {
        int x = rand() % modulo; 
        int y = rand() % modulo; 

        if(rand() % 2)
            x *= -1;

        if(rand() % 2)
            y *= -1;

        std::pair<int, int> P;
        P.first = x;
        P.second = y;
        if(S.find(P) == S.end())
        {
            S.insert(P);
            fileToWrite << x << " " << y << std::endl;
        }
        else
        {
            i--;
        }
    }

    fileToWrite.close();
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int NUM_OF_TESTS = 100;
    if(argc > 1)
        NUM_OF_TESTS = atoi(argv[1]);

    std::cout << "Generating data..." << std::endl;


    time_t seed;
    srand(time(&seed));

    for(int i = 0; i < NUM_OF_TESTS; i++)
    {
        std::string fileName = "./tests/in/" + std::to_string(i) + ".in";

        if(i < 10)
            writeTest(30, fileName);
        else if(i < 100)
            writeTest(3000, fileName);
        else
            writeTest(30000, fileName);
    }
}
