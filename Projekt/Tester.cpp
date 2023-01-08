//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: Tester.cpp                        //
//                                            //
//    Program do testowania                   //
//                                            //
//############################################//

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    for(int i = 0; i < 1000; i++)
    {
        std::string testFileIn = "./tests/in/" + std::to_string(i) + ".in";
        std::string testFileOut = "./tests/out/" + std::to_string(i) + ".out";
        std::string fileToTest = "./tests/toTest/" + std::to_string(i) + ".out";

        if(system(("./ProstokatBrute.x < " + testFileIn + " > " + testFileOut).c_str()))
            break;
        if(system(("./Prostokat.x < " + testFileIn + " > " + fileToTest).c_str()))
            break;

        if(system(("diff " + testFileOut + " " + fileToTest).c_str()))
        {
            std::cout << i << " ANS" << std::endl;
            return 0;
        }
        else
            std::cout << i << " OK" << std::endl;
    }
}
