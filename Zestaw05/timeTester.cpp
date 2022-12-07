//############################################//
//                                            //
//    Jan Kwinta                25.11.2022    //
//                                            //
//                                            //
//    Zestaw05: Proste algorytmy sortowania   //
//    Plik: timeTester.cpp                    //
//                                            //
//    Zadanie 1. Implementacja prostych       //
//               algorytmow sortowania;       //
//               Mierzenie czasu wykonania    //
//                                            //
//############################################//

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::string programToTest;
    if(argc > 1)
        programToTest = argv[1];
    else
        return 0;

    for(int n = 1000; n < 100000; n += 1000)
    {
        std::string cmd;
        cmd += "./Generator.x ";
        cmd += std::to_string(n);
        cmd += " 10000 | ./";
        cmd += programToTest;
        cmd += ".x > data.out 2>> times";
        cmd += programToTest;
        cmd += ".txt";

        if(std::system(cmd.c_str()) != 0)
            std::cerr << "command error" << std::endl;
    }
}