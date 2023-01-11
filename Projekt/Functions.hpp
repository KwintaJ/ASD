//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: Functions.hpp                     //
//                                            //
//    Plik naglowkowy zawierajacy przydatne   //
//    funkcje                                 //
//                                            //
//############################################//

#include <utility>
#include <iostream>

/* funkcja zwracajaca wieksza z dwoch liczb calkowitych */
int maxOf(const int &A, const int &B)
{
    if(A >= B)
        return A;
    return B;
}

/* MERGESORT */
template<class Compare, class Container>
Container merge(Container &left, Container &right, Compare comp)
{
    Container result;

    int iL = 0, iR = 0;
    while(iL < left.size() && iR < right.size())
    {
        if(comp(left[iL], right[iR]))
        {
            result.push_back(left[iL]);
            iL++;
        }
        else
        {
            result.push_back(right[iR]);
            iR++;
        }
    }

    while(iL < left.size())
    {
        result.push_back(left[iL]);
        iL++;
    }
    while(iR < right.size())
    {
        result.push_back(right[iR]);
        iR++;
    }

    return result;
}

/* funkcja sortujaca kontener v mergesortem */
template<class Compare, class Container>
Container sortContainer(Container &v, Compare comp)
{
    if((int)v.size() <= 1)
        return v;

    Container left;
    Container right;

    for(int i = 0; i < (int)v.size(); i++)
    {
        if(i < ((int)v.size() / 2))
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }

    left = sortContainer(left, comp);
    right = sortContainer(right, comp);

    return merge(left, right, comp);
}