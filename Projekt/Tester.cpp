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

    int choice = 0, NUM_OF_TESTS = 0;
    std::cout << "Do you want to generate new test data?\n1. Yes\n2. No" << std::endl;
    std::cin >> choice;

    if(choice != 1 && choice != 2)
        return 0;

    if(choice == 1)
    {
        std::cout << "How many tests do you want to generate?" << std::endl;
        std::cin >> NUM_OF_TESTS;

        if(system(("./Generator.x " + std::to_string(NUM_OF_TESTS)).c_str()))
            return 0;

        std::cout << "Brute-forcing data..." << std::endl;

        for(int i = 0; i < NUM_OF_TESTS; i++)
        {
            std::string testFileIn = "./tests/in/" + std::to_string(i) + ".in";
            std::string testFileOut = "./tests/out/" + std::to_string(i) + ".out";

            if(system(("./ProstokatBrute.x < " + testFileIn + " > " + testFileOut).c_str()))
                return 0;
        }
    }

    std::cout << "Ready for testing. Type How many tests do you want to run" << std::endl;
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
            std::cout << "All tests passed" << std::endl;

}
