#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point{
    Point(){
        x = 0;
        y = 0;
    }
    int x;
    int y;
};

bool comparePoint(const Point &p1, const Point &p2)
{
    if(p1.y < p2.y)
    {
        return true;
    }
    else if(p1.y == p2.y)
    {
        if(p1.x < p2.x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<Point> vList;
    auto nInput = 0;
    Point stPoint;

    cin >> nInput;

    for(int i = 0 ; i < nInput ; ++i)
    {
        cin >> stPoint.x >> stPoint.y;
        vList.push_back(stPoint);
    }

    sort(vList.begin(), vList.end(), comparePoint);

    for(const Point& point : vList)
    {
        cout << point.x << " " << point.y << "\n";
    }

    return 0;
}