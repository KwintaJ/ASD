//############################################//
//                                            //
//    Jan Kwinta                xx.xx.2023    //
//                                            //
//                                            //
//    Projekt: Prostokat                      //
//    Plik: IntervalTree.hpp                  //
//                                            //
//    Funkcje drzewa przedzialowego           //
//                                            //
//############################################//

#ifndef INTERVALTREE
#define INTERVALTREE

/* dzialanie drzewa - w tym przypadku max() */
int functionF(const int &A, const int &B)
{
    if(A >= B)
        return A;
    return B;
}

/* zapytanie o functionF() na przedziale [p, q) */
int query(int tree[], int modf[], int v, int left, int right, int p, int q);

/* zepchniecie modyfikatorow */
void push(int tree[], int modf[], int v, int left, int right)
{
    if(modf[v] != 0)
    {
        modf[2*v] += modf[v];
        modf[2*v+1] += modf[v];
        modf[v] = 0;
        int middle = (left + right) / 2;
        int child1 = query(tree, modf, 2*v, left, middle, left, middle);
        int child2 = query(tree, modf, 2*v+1, middle, right, middle, right);
        tree[v] = functionF(child1, child2);
    }
}

/* zapytanie */
int query(int tree[], int modf[], int v, int left, int right, int p, int q)
{
    if(p <= left && q >= right)
        return tree[v] + modf[v];

    if(right <= p || left >= q)
        return -1;

    push(tree, modf, v, left, right);

    int middle = (left + right) / 2;
    int child1 = query(tree, modf, 2*v, left, middle, p, q);
    int child2 = query(tree, modf, 2*v+1, middle, right, p, q);

    return functionF(child1, child2);
}

/* modyfikacja wartosci o +x na przedziale [p, q) */
void update(int tree[], int modf[], int v, int left, int right, int p, int q, int x)
{
    if(p <= left && q >= right)
    {
        modf[v] += x;
        return;
    }

    if(right <= p || left >= q)
        return;

    push(tree, modf, v, left, right);

    int middle = (left + right) / 2;
    update(tree, modf, 2*v, left, middle, p, q, x);
    update(tree, modf, 2*v+1, middle, right, p, q, x);

    int child1 = query(tree, modf, 2*v, left, middle, left, middle);
    int child2 = query(tree, modf, 2*v+1, middle, right, middle, right);

    tree[v] = functionF(child1, child2);
}
#endif
