#include <iostream>
#include <limits>

using namespace std;

constexpr int kBigDec = numeric_limits<int>::max();
constexpr int kInfinite = 1e9;

int N, M;

int graph[101][101];

int main()
{
    cin >> N >> M;

    int place1, place2;
    int X, K;

    for(int i = 0 ; i < 101 ; ++i)
    {
        fill(graph[i], graph[i]+101, kInfinite);
    }

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            if(i == j)
            {
                graph[i][i] = 0;
            }
        }
    }

    for(int i = 0 ; i < M ; ++i)
    {
        cin >> place1 >> place2;
        graph[place1][place2] = graph[place2][place1] = 1;
    }

    cin >> X >> K;

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            for(int k = 1 ; k <= N ; ++k)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    long long distance = graph[1][K] + graph[K][X];
    
    if(distance >= kInfinite)
    {
        cout << "-1" << "\n";
    }
    else{
        cout << distance << "\n";
    }

    return 0;
}