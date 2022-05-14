#include <iostream>
#include <string>

using namespace std;

int mapSize = 0;
constexpr int moveIndex = 4;
constexpr int moveX[moveIndex] = {0, 0, -1, 1};
constexpr int moveY[moveIndex] = {-1, 1, 0, 0};
constexpr char moveType[moveIndex] = {'L', 'R', 'U', 'D'};

bool isError(const int& x, const int& y)
{
    return (x<1 || y<1 || x > mapSize || y > mapSize) ? true : false;
}

int main()
{
    int x = 1;
    int y = 1;
    int nX, nY = 0;
    constexpr char space = ' ';
    string strPlans;

    cin >> mapSize;
    cin.ignore();
    getline(cin, strPlans);

    // cout << mapSize << " " << strPlans << endl;

    for(const char& c : strPlans)
    {
        if(c == space)
        {
            continue;
        }
        
        nX = -1;
        nY = -1;

        for(int i = 0 ; i < moveIndex ; ++i)
        {
            if(c == moveType[i])
            {
                nX = x + moveX[i];
                nY = y + moveY[i];
                break;
            }
        }

        if(isError(nX, nY))
        {
            continue;
        }
        x = nX;
        y = nY;
    }

    cout << x << " " << y;

    return 0;
}