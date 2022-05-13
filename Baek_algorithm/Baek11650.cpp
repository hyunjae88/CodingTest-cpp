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
    if(p1.x < p2.x)
    {
        return true;
    }
    else if(p1.x == p2.x)
    {
        if(p1.y < p2.y)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<Point> vPoints;
    int input = 0;
    Point point;

    cin >> input;

    for(int i = 0 ; i < input ; ++i)
    {
        cin >> point.x >> point.y;
        vPoints.push_back(point);
    }

    sort(vPoints.begin(), vPoints.end(), comparePoint);

    for(const Point& point : vPoints)
    {
        cout << point.x << " "  << point.y << "\n";
    }

    return 0;
}