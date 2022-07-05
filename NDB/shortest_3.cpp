#include <iostream>



using namespace std;

int N, M, C;

constexpr int kInfinite = 1e9;

int graph[30001][30001];

int main()
{
    int X, Y, Z;

    cin >> N >> M >> C;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            graph[i][j] = kInfinite;
            if(i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    for(int i = 0 ; i < M ; ++i)
    {
        cin >> X >> Y >> Z;
        graph[X][Y] = Z;
    }

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            for(int k = 1 ; k <= N ; ++k)
            {
                graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
            }
        }
    }

    int cityCnt, maxTime = 0;

    for(int i = 1 ; i <= N ; ++i)
    {

        if( (graph[C][i] != kInfinite) && (graph[C][i] != 0))
        {
            cityCnt++;
            if(graph[C][i] > maxTime)
            {
                maxTime = graph[C][i];
            }
            
        }
    }

    cout << cityCnt << " " << maxTime;



    return 0;
}