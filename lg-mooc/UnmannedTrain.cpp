#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int N;
int M;
int map[50+10][50+10];

struct XY{
    XY(){
        x = 0;
        y = 0;
    }
    int x;
    int y;
};

vector<XY> L1;
vector<XY> L2;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void InputData(void){
    cin >> N >> M;
    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= M ; ++j)
        {
            cin >> map[i][j];
        }
    }
}

int CalcDistance(int x1, int y1, int x2, int y2)
{
    return (abs(x1-x2) + abs(y1-y2))-1;
}

void Fill(int x, int y, int lv)
{
    if(map[x][y] != 1)  return;

    map[x][y] = 0;
    XY tempXY;
    tempXY.x = x;
    tempXY.y = y;

    if(lv == 1)
    {
        L1.push_back(tempXY);
    }
    else if(lv == 2)
    {
        L2.push_back(tempXY);
    }

    for(int i = 0 ; i < 4 ; ++i)
    {
        Fill(x+dx[i], y+dy[i], lv);
    }
}

int Solve()
{
    int minDistance = numeric_limits<int>::max();

    XY tempXY;
    bool isFirst = true;
    int startLevel = 1;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= M ; ++j)
        {
            if(map[i][j] == 1)
            {
                Fill(i,j,startLevel);
                startLevel++;
            }
            
        }
    }

    int Distance = 0;
    for(int i = 0 ; i < L1.size() ; ++i)
    {
        for(int j = 0 ; j < L2.size() ; ++j)
        {
            Distance = CalcDistance(L1[i].x, L1[i].y, L2[j].x, L2[j].y);
            if(Distance < minDistance)
            {
                minDistance = Distance;
            }
                
        }
    }
    return minDistance;
}

int main()
{
    int ans = -1;
    InputData();
    ans = Solve();
    cout << ans << endl;
    return 0;
}