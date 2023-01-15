//############################################//
//                                            //
//    Jan Kwinta                15.01.2023    //
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

/* INDEX LOWER BOUND AND UPPER BOUND */
template<class T, class Compare, class Container>
int lowBound(Container &v, T P, Compare comp)
{
    int it, count, step;
    count = v.size();
    int first = 0;

    while(count > 0)
    {
        it = first; 
        step = count / 2; 
        it += step;
 
        if(comp(v[it], P))
        {
            it++;
            first = it; 
            count -= step + 1; 
        }
        else
            count = step;
    }
 
    return first;
}

template<class T, class Compare, class Container>
int upBound(Container &v, T P, Compare comp)
{
    int it, count, step;
    count = v.size();
    int first = 0;
 
    while(count > 0)
    {
        it = first; 
        step = count / 2; 
        it += step;
 
        if(!comp(P, v[it]))
        {
            it++;
            first = it;
            count -= step + 1;
        } 
        else
            count = step;
    }
 
    return first;
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