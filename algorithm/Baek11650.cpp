#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct point{
    point(){
        x = 0;
        y = 0;
    }
    int x;
    int y;
};

bool comparePoint(const point &p1, const point &p2)
{
    if(p1.x > p2.x)
    {
        return true;
    }
    else if(p1.x == p2.x)
    {
        if(p1.y > p2.y)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<point> vList;
    auto nInput = 0;
    point stPoint;

    cin >> nInput;

    for(int i = 0 ; i < nInput ; ++i)
    {
        cin >> stPoint.x >> stPoint.y;
        vList.push_back(stPoint);
    }

    sort(vList.begin(), vList.end(), comparePoint);

    for(int i = 0 ; i < nInput ; ++i)
    {
        cout << vList.back().x << " " << vList.back().y << "\n";
        vList.pop_back();
    }

    return 0;
}