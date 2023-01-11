//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: Point.hpp                         //
//                                            //
//    Struktura reprezentujaca punkt          //
//    na plaszczyznie i przydatne funkcje     //
//                                            //
//############################################//

#ifndef POINT
#define POINT

struct Point
{
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    int x;
    int y;
};

/* porownywanie dwoch punktow */
bool LessByX(const Point &A, const Point &B)
{
    if(A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}
bool LessByY(const Point &A, const Point &B)
{
    if(A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}
bool operator==(const Point &A, const Point &B)
{
    if(A.x == B.x && A.y == B.y)
        return true;
    return false;
}

struct {
    bool operator()(const Point &A, const Point &B)
    {
        if(A.x == B.x)
            return A.y < B.y;
        return A.x < B.x;
    }
} SortPointsByX;

struct {
    bool operator()(const Point &A, const Point &B)
    {
        if(A.y == B.y)
            return A.x < B.x;
        return A.y < B.y;
    }
} SortPointsByY;

#endif
