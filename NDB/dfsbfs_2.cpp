#include <iostream>
#include <deque>

using namespace std;

int N, M;
int map[201][201];
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

deque<pair<int, int>> myQueue;

int bfs(int x, int y)
{
    int nX, nY = 0;
    int pathLength = 1;
    myQueue.push_back(make_pair(x,y));

    while(!myQueue.empty())
    {
       for(int i = 0 ; i < 4 ; ++i)
       {
           
            nX = (myQueue.front().first + dx[i]);
            nY = myQueue.front().second + dy[i];
            myQueue.pop_front();
            if(nX == N && nY == M)
            {
                return map[nX][nY];
            }

            if(nX < 1 || nX > N || nY < 1 || nY > M)
            {
                continue;
            }
            if(map[nX][nY] == 0)
            {
                continue;
            } 
            else if(map[nX][nY] == 1)
            {
                cout << "x : " << x << " y : " << y;
                map[nX][nY] = ++pathLength;
                myQueue.push_back(make_pair(nX,nY));
            }
            
       }
    }

    return false;
}


int main()
{
    cin >> N >> M;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= M ; ++j)
        {
            cin >> map[i][j];
        }
    }    

    cout << bfs(1, 1) << endl;;

    return 0;
}