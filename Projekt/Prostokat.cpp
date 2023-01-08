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
#include <vector>
#include <algorithm>
#include <deque>

struct Point
{
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    int x = 0;
    int y = 0;
};

bool operator<(const Point &A, const Point &B)
{
    if(A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}

/* query declaration */
int query(int tree[], int modf[], int v, int left, int right, int p, int q);

/* pushing modificators */
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
        tree[v] = std::max(child1, child2);
    }
}

/* query */
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

    return std::max(child1, child2);
}

/* interval tree update +x on range (p, q) */
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

    tree[v] = std::max(child1, child2);
}

void throwInTree(int tree[], int modf[], Point P)
{

}

void pullOutFromTree(int tree[], int modf[], Point P)
{

}

//#############################################################################
int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    /* input */
    int w, h, n;
    std::cin >> w >> h >> n;

    /* all points on the plane */
    std::vector<Point> allPoints;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        allPoints.push_back(Point(a, b));
    }

    /* interval max() tree */
    int tree[4 * 15000 + 1] = {0};
    /* modificator array */
    int modf[4 * 15000 + 1] = {0};

    int Output = 0;

    std::sort(allPoints.begin(), allPoints.end());

    std::deque<Point> processed;
    int i = 0;
    while(i < n)
    {
        Point P = allPoints[i];

        else if(processed.empty() || P.x - processed[0].x <= w)
        {
            processed.push_back(P);
            throwInTree(tree, modf, P);
            i++;
        }
        else
        {
            Output = std::max(Output, query(tree, modf, 1, 1, n, 1, n));
            pullOutFromTree(tree, modf, processed[0]);
            processed.pop_front();
        }
    }
    Output = std::max(Output, query(tree, modf, 1, 1, n, 1, n));

    std::cout << Output << std::endl;
}
