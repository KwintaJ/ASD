//############################################//
//                                            //
//    Jan Kwinta                15.01.2023    //
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

    int choice = 0, NUM_OF_TESTS = 0;
    std::cout << "Czy chcesz wygenerowac nowe testy?\n1. Tak\n2. Nie" << std::endl;
    std::cin >> choice;

    if(choice != 1 && choice != 2)
        return 0;

    if(choice == 1)
    {
        std::cout << "Ile testow chcesz wygenerowac?" << std::endl;
        std::cin >> NUM_OF_TESTS;

        if(system(("./Generator.x " + std::to_string(NUM_OF_TESTS)).c_str()))
            return 0;

        std::cout << "Brute-forcing..." << std::endl;

        for(int i = 0; i < NUM_OF_TESTS; i++)
        {
            std::string testFileIn = "./tests/in/" + std::to_string(i) + ".in";
            std::string testFileOut = "./tests/out/" + std::to_string(i) + ".out";

            if(system(("./ProstokatBrute.x < " + testFileIn + " > " + testFileOut).c_str()))
                return 0;
        }
    }

    std::cout << "Gotowe do testowania. Ile testow chcesz uruchomic?" << std::endl;
    NUM_OF_TESTS = 0;
    std::cin >> NUM_OF_TESTS;

    for(int i = 0; i < NUM_OF_TESTS; i++)
    {
        std::string testFileIn = "./tests/in/" + std::to_string(i) + ".in";
        std::string testFileOut = "./tests/out/" + std::to_string(i) + ".out";
        std::string fileToTest = "./tests/toTest/" + std::to_string(i) + ".out";
        
        if(system(("./Prostokat.x < " + testFileIn + " > " + fileToTest).c_str()))
            return 0;

        if(system(("diff " + testFileOut + " " + fileToTest).c_str()))
        {
            std::cout << i << " ANS" << std::endl;
            return 0;
        }
        else
            std::cout << i << " OK" << std::endl;
    }
            std::cout << "Wszystkie testy zaliczone" << std::endl;

}
