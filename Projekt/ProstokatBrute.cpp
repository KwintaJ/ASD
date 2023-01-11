//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: ProstokatBrute.cpp                //
//                                            //
//    Program wykorzystujacy brute-force      //
//                                            //
//############################################//

#include <iostream>
#include <vector>
#include <algorithm>

#include "Point.hpp"

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int w, h, n;
    std::cin >> w >> h >> n;
    std::vector<Point> allPoints;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        allPoints.push_back(Point(a, b));
    }

    std::sort(allPoints.begin(), allPoints.end(), ComparePointsByX);

    int Output = 0;
    int inside = 0;

    for(int i = 0; i < n; i++)
    {
        auto it = allPoints.begin() + i;

        std::vector<Point> rightColumn(it, upper_bound(it, allPoints.end(), Point(it->x + w, 30001), ComparePointsByX));
        auto it2 = it;
        while(it2 != allPoints.begin())
        {
            it2--;
            if(it2->x != it->x)
                break;
            rightColumn.push_back(*it2);
        }

        sort(rightColumn.begin(), rightColumn.end(), ComparePointsByY);

        for(auto it3 = lower_bound(rightColumn.begin(), rightColumn.end(), Point(-30001, it->y - h), ComparePointsByY);
        it3 != rightColumn.end(); it3++)
        {
            auto it4 = it3;

            inside = 0;
            while(it4 != rightColumn.end() && it4->y - it3->y <= h)
            {
                inside++;
                it4++;
            }
            Output = std::max(Output, inside);
        }
    }

    std::cout << Output << std::endl;
}
