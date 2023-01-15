//############################################//
//                                            //
//    Jan Kwinta                15.01.2023    //
//                                            //
//                                            //
//    Projekt: 7. Prostokat                   //
//    Plik: Prostokat.cpp                     //
//                                            //
//    Program wzorcowy                        //
//                                            //
//############################################//

#include <iostream>

#include "Functions.hpp"      // funkcje maxOf(), upBound(), lowBound() i sortContainer()
#include "Point.hpp"          // struktura reprezentujaca punkt na plaszczyznie
#include "IntervalTree.hpp"   // funkcje drzewa przedzialowego
#include "Vector.hpp"         // wektor
#include "LinkedQueue.hpp"    // kolejka wskaznikowa

const int MAX_NUMBER_OF_POINTS = 15000;
const int MAX_COORDINATE = 30000;
const int MIN_COORDINATE = -30000;

/* struktura reprezentujaca przedzial liczbowy */
struct Range
{
    int left = MIN_COORDINATE;
    int right = MAX_COORDINATE;

    Range operator++()
    {
        left++;
        right++;
        return *this;
    }
};

/* obliczenie przedzialu na ktorym nalezy zaaktualizowac wartosci w drzewie przedzialowym */
Range calculateRange(Vector<Point> &allPointsByY, Point P, int n, int h);

/* funkcje aktualizujace wartosci drzewa */
void throwInTree(int tree[], int modf[], Vector<Point> &allPointsByY, int n, int h, Point P);
void pullOutFromTree(int tree[], int modf[], Vector<Point> &allPointsByY, int n, int h, Point P);

//#################################################################################################
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
    /* zmienna przechowujaca wynik */
    int Result = 0;

    /* sortowanie punktow */
    Vector<Point> allPointsSortedByX = sortContainer(allPoints, ComparePointsByX);
    Vector<Point> allPointsSortedByY = sortContainer(allPoints, ComparePointsByY);

    Queue<Point, MAX_NUMBER_OF_POINTS> currentlyProcessed; 
                        // kolejka punktow aktualnie przetwarzanych punktow
    int i = 0;
    
    /* ============ miotla - algorytm zachlanny ============ */
    while(i < n)
    {
        Point P = allPointsSortedByX[i]; // nowy punkt

        /* zapytanie - czy trzeba wyrzucic punkt najbardziej na lewo */
        if(currentlyProcessed.empty() || (P.x - currentlyProcessed.front().x) <= w)
        {
            /* nie trzeba - mozemy dodac P do currentlyProcessed i zaaktualizowac drzewo */

            currentlyProcessed.push(P);
            throwInTree(tree, modf, allPointsSortedByY, n, h, P);
            i++;
        }
        else
        {
            /* trzeba - zanim wiec dodamy P musimy usunac najstarszy 
               element kolejki currentlyProcessed i zaaktualizowac drzewo

               zanim go usuniemy chcemy dowiedziec sie 
               jaki jest max() na calym przedziale [1, n) */
            Result = maxOf(Result, query(tree, modf, 1, 1, n, 1, n)); 
            pullOutFromTree(tree, modf, allPointsSortedByY, n, h, currentlyProcessed.front());
            currentlyProcessed.pop();
        }
    }
    Result = maxOf(Result, query(tree, modf, 1, 1, n, 1, n));

    /* ==== output ==== */
    std::cout << Result << std::endl;
}
//#################################################################################################

Range calculateRange(Vector<Point> &allPointsByY, Point P, int n, int h)
{
    Range R;

    /* przedzial na ktorym aktualizujemy drzewo przedzialowe jest ograniczony
            
            z lewej strony najmniejszym punktem o wspolrzednej y o h mniejszej niz 
            wspolrzedna y punktu P  

            z prawej strony najwiekszym punktem o wspolrzednej y takiej samej jak
            ma punkt P */

    R.left = upBound(allPointsByY, Point(MIN_COORDINATE - 1, P.y - h), ComparePointsByY);
    R.right = lowBound(allPointsByY, Point(MAX_COORDINATE + 1, P.y), ComparePointsByY);
        
    return ++R;
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
