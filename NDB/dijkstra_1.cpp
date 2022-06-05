#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct DstData{
    int dst;
    int distance;
};


constexpr int kBigDec = numeric_limits<int>::max();
constexpr int kReserveVector = 10000;
constexpr int kNodeMaxCnt = 100001;

int N, M;
int startNode;
vector<DstData> graph[kNodeMaxCnt];



int getShortNode(vector<int>& shortestDistance, vector<bool>& visited)
{
    int minValue = kBigDec;
    int index = 0;
    for(int i = 1 ; i <= N ; ++i)
    {
        if((shortestDistance[i] < minValue) && (visited[i]==false))
        {
            minValue = shortestDistance[i];
            index = i;
        }
    }
    return index;
}

int dijkstra(vector<int>& shortestDistance, vector<bool>& visited, int startNode)
{
    shortestDistance[startNode] = 0;
    visited[startNode] = true;

    for(DstData& dstData : graph[startNode])
    {
        shortestDistance[dstData.dst] = dstData.distance;
    }

    int checkingNode = 0;
    int defaultDistance = 0;
    int tempDistance = 0;

    for(int i = 1 ; i <= N ; ++i)
    {
        checkingNode = getShortNode(shortestDistance, visited);
        visited[checkingNode] = true;
        defaultDistance = shortestDistance[checkingNode];

        for(DstData& dstData : graph[checkingNode])
        {
            tempDistance = defaultDistance + dstData.distance;
            if(tempDistance < shortestDistance[dstData.dst] )
            {
                shortestDistance[dstData.dst] = tempDistance;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> startNode;

    vector<bool> visited(N+1, false);
    vector<int> shortestDisance(N+1, kBigDec);
    shortestDisance[0] = -1;
    
    int src = 0;
    int dst = 0;
    DstData inputDstData;

    for(int i = 0 ; i < M ; ++i)
    {
        cin >> src >> inputDstData.dst >> inputDstData.distance;
        graph[src].emplace_back(inputDstData);
    }

    dijkstra(shortestDisance, visited, startNode);

    int tempIndex = 0;
    for(int& sol : shortestDisance)
    {
        cout << tempIndex++ << " " << sol << "\n";
    }

    // cout << "N : " << N << endl;
    // cout << "M : " << M << endl;
    // cout << "startNode : " << startNode << endl;
    
    // for(int i = 0 ; i < N ; ++i)
    // {
    //     for(DstData& dstData : graph[i])
    //     {
    //         cout << i << " " << dstData.dst << " " << dstData.distance << "\n";
    //     }
    // }

    return 0;
}