//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: Prostokat.cpp                     //
//                                            //
//    Program wzorcowy                        //
//                                            //
//############################################//

#include <iostream>

#include "Functions.hpp"      // funkcje maxOf() i sortContainer()
#include "Point.hpp"          // struktura reprezentujaca punkt na plaszczyznie
#include "IntervalTree.hpp"   // funkcje drzewa przedzialowego
#include "Vector.hpp"         // wektor
#include "LinkedQueue.hpp"    // kolejka wskaznikowa

const int MAX_NUMBER_OF_POINTS = 15000;

/* struktura reprezentujaca przedzial */
struct Range
{
    int left = -30001;
    int right = 30001;
};

/* wyszukanie punktu o danej wspolrzednej y z tablicy wszystkich punktow 
   posortowanej po wspolrzednych y; funkcja zwraca indeks w tablicy; O(log n) */
int binsearch(Vector<Point> &allPointsByY, Point P, int BSleft, int BSright);

/* obliczenie przedzialu na ktorym nalezy zaaktualizowac wartosci w drzewie przedzialowym */
Range calculateRange(Vector<Point> &allPointsByY, Point P, int n, int h);

/* funkcje aktualizujace wartosci drzewa */
void throwInTree(int tree[], int modf[], Vector<Point> &allPointsByY, int n, int h, Point P);
void pullOutFromTree(int tree[], int modf[], Vector<Point> &allPointsByY, int n, int h, Point P);

//#################################################################################################################################################################################
int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    /* input */
    int w, h, n;
    Vector<Point> allPoints;

    std::cin >> w >> h >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        allPoints.push_back(Point(a, b));
    }

    /* drzewo przedzialowe max() */
    int tree[4 * MAX_NUMBER_OF_POINTS + 1] = {0};
    /* tablica modyfikatorow */
    int modf[4 * MAX_NUMBER_OF_POINTS + 1] = {0};

    int Output = 0;

    /* sortowanie punktow */
    Vector<Point> allPointsSortedByX = sortContainer(allPoints, ComparePointsByX);
    Vector<Point> allPointsSortedByY = sortContainer(allPoints, ComparePointsByY);

    Queue<Point, MAX_NUMBER_OF_POINTS> currentlyProcessed; // kolejka punktow aktualnie przetwarzanych
    int i = 0;
    
    /* ============ miotla - algorytm zachlanny ============ */
    while(i < n)
    {
        Point P = allPointsSortedByX[i]; // nowy punkt

        /* zapytanie - czy trzeba wyrzucic punkt najbardziej na lewo */
        if(currentlyProcessed.empty() || (P.x - currentlyProcessed.front().x) <= w)
        {
            /* nie trzeba - mozemy dodac P do currentlyProcessed */
            currentlyProcessed.push(P);
            throwInTree(tree, modf, allPointsSortedByY, n, h, P);
            i++;
        }
        else
        {
            /* trzeba - zanim wiec dodamy P musimy usunac najstarszy 
               element kolejki currentlyProcessed */

            /* zanim go usuniemy chcemy dowiedziec sie jaki jest max() na calym przedziale [1, n) */
            Output = maxOf(Output, query(tree, modf, 1, 1, n, 1, n));
            pullOutFromTree(tree, modf, allPointsSortedByY, n, h, currentlyProcessed.front());
            currentlyProcessed.pop();
        }
    }
    Output = maxOf(Output, query(tree, modf, 1, 1, n, 1, n));

    std::cout << Output << std::endl;
}
//#################################################################################################################################################################################

int binsearch(Vector<Point> &allPointsByY, Point P, int BSleft, int BSright)
{
    while (BSleft <= BSright)
    {
        int BSmiddle = (BSleft + BSright) / 2;

        if(allPointsByY[BSmiddle].y < P.y)
        {
            BSleft = BSmiddle + 1;
        } 
        else if(allPointsByY[BSmiddle].y > P.y)
        {
            BSright = BSmiddle - 1;
        }
        else
        {
            return BSmiddle;
        }
    }

    return -1;
}

Range calculateRange(Vector<Point> &allPointsByY, Point P, int n, int h)
{
    Range R;

    int index = binsearch(allPointsByY, P, 0, n - 1);
    if(index == -1)
        return R;

    int j = index;
    while(j < n)
    {
        if(allPointsByY[index].y == allPointsByY[j].y)
        {
            R.right = j;
            j++;
        }
        else
            break;
    }

    j = index;
    while(j >= 0)
    {
        if(allPointsByY[index].y - allPointsByY[j].y <= h)
        {
            R.left = j;
            j--;
        }
        else
            break;
    }

    R.left++;
    R.right+=2;
    return R;
}

void throwInTree(int tree[], int modf[], Vector<Point> &allPointsByY, int n, int h, Point P)
{
    Range R = calculateRange(allPointsByY, P, n, h);
    update(tree, modf, 1, 1, n, R.left, R.right, 1);
}

void pullOutFromTree(int tree[], int modf[], Vector<Point> &allPointsByY, int n, int h, Point P)
{
    Range R = calculateRange(allPointsByY, P, n, h);
    update(tree, modf, 1, 1, n, R.left, R.right, -1);
}
