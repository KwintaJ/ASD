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

bool operator==(const Point &A, const Point &B)
{
    if(A.x == B.x && A.y == B.y)
        return true;
    return false;
}

struct {
    bool operator()(const Point &A, const Point &B)
    {
        if(A.y == B.y)
            return A.x < B.x;
        return A.y < B.y;
    }
} SortPointsByY;

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

struct Range
{
    int left = -30001;
    int right = 30001;
};

int binsearch(std::vector<Point> &allPointsByY, Point P, int BSleft, int BSright)
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

Range calculateRange(std::vector<Point> &allPointsByY, Point P, int n, int h)
{
    Range R;

    int index = binsearch(allPointsByY, P, 0, n - 1);
    if(index == -1)
        return R;

    R.right = index;

    int j = index;
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

    R.right++;
    return R;
}

void throwInTree(int tree[], int modf[], std::vector<Point> &allPointsByY, int n, int h, Point P)
{
    Range R = calculateRange(allPointsByY, P, n, h);
    update(tree, modf, 1, 1, n, R.left, R.right, 1);
}

void pullOutFromTree(int tree[], int modf[], std::vector<Point> &allPointsByY, int n, int h, Point P)
{
    Range R = calculateRange(allPointsByY, P, n, h);
    update(tree, modf, 1, 1, n, R.left, R.right, -1);
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
    std::vector<Point> allPointsSortedByY;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        allPoints.push_back(Point(a, b));
        allPointsSortedByY.push_back(Point(a, b));
    }

    /* interval max() tree */
    int tree[4 * 15000 + 1] = {0};
    /* modificator array */
    int modf[4 * 15000 + 1] = {0};

    int Output = 0;

    std::sort(allPoints.begin(), allPoints.end());
    sort(allPointsSortedByY.begin(), allPointsSortedByY.end(), SortPointsByY);

    std::deque<Point> processed;
    int i = 0;
    while(i < n)
    {
        Point P = allPoints[i];

        if(processed.empty() || P.x - processed[0].x <= w)
        {
            processed.push_back(P);
            throwInTree(tree, modf, allPointsSortedByY, n, h, P);
            // std::cerr << "for i = " << i << " tree[1] = " << tree[1] << std::endl;
            i++;
        }
        else
        {
            Output = std::max(Output, query(tree, modf, 1, 1, n, 1, n));
            pullOutFromTree(tree, modf, allPointsSortedByY, n, h, processed[0]);
            processed.pop_front();
        }
    }
    Output = std::max(Output, query(tree, modf, 1, 1, n, 1, n));

    std::cout << Output << std::endl;
}
