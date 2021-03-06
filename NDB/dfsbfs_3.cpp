#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int N, M = 0;
int frame[1000][1000];

//재귀적인 풀이 방법
bool dfs(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >=M)
    {
        return false;
    }
    if(frame[x][y] == 0)
    {
        frame[x][y] = 1;
        for(int i = 0 ; i < 4 ; ++i)
        {
            dfs(x+dx[i], y+dy[i]);
        }
        return true;
    }
    return false;
}

//반복문 풀이방법
bool dfs2(int x, int y)
{
    vector<pair<int, int>> myVector;
    myVector.push_back(make_pair(x,y));
    bool result = false;

    while(myVector.empty())
    {
        
        x = myVector.back().first;
        y = myVector.back().second;
        myVector.pop_back();

        if(x < 0 || x >= N || y < 0 || y >=M)
        {
            continue;
        }

        if(frame[x][y] == 0)
        {
            result = true;
            frame[x][y] = 1;
            for(int i = 0 ; i < 4 ; ++i)
            {
                myVector.push_back(make_pair(x+dx[i], y+dy[i]));
            }
        }
    }

    return result;
}


int main()
{

    int result = 0;
    int resultLoop = 0;

    cin >> N >> M;

    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            cin >> frame[i][j];
        }
    }

    //재귀함수를 활용한 DFS 활용
    // for(int i = 0 ; i < N ; ++i)
    // {
    //     for(int j = 0 ; j < M ; ++j)
    //     {
    //         if(dfs(i, j))
    //         {
    //             ++result;
    //         }
    //     }
    // }

    //반복문을 활용한 DFS 활용
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            if(dfs(i,j))
            {
                ++resultLoop;
            }
        }
    }

    // cout << result << endl;
    cout << resultLoop << endl;

    return 0;
}