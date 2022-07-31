#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct DstData{
    int dst;
    int distance;
};

constexpr int kBigDec = numeric_limits<int>::max();
constexpr int kMaxNode = 100001;

int N, M;
int startNode;
vector<DstData> graph[kMaxNode];
vector<int>     shortestDistance(kMaxNode, kBigDec);

void dijkstra(int startNode)
{
    priority_queue<pair<int, int>> pq;

    pq.emplace(0, startNode);
    shortestDistance[startNode] = 0;

    int tempDistance;
    int tempNode;
    int costDistance = 0;

    while(!pq.empty())
    {
        tempDistance    = -pq.top().first;
        tempNode        = pq.top().second;
        pq.pop();

        if(shortestDistance[tempNode] < tempDistance)
        {
            continue;
        }

        for(const DstData& dstData : graph[tempNode])
        {
            costDistance = tempDistance + dstData.distance;
            if(costDistance < shortestDistance[dstData.dst])
            {
                shortestDistance[dstData.dst] = costDistance;
                pq.emplace(-costDistance, dstData.dst);
            }
        }
    }
}

int main()
{
    DstData inputDstData;
    int     inputSrc;
    
    cin >> N >> M >> startNode;

    for(int i = 0 ; i < M ; ++i)
    {
        cin >> inputSrc >> inputDstData.dst >> inputDstData.distance;
        graph[inputSrc].emplace_back(inputDstData);
    }

    dijkstra(startNode);

    for(int i = 1 ; i <= N ; ++i)
    {
        if(shortestDistance[i] == kBigDec)
        {
            cout << "INFINITY" << "\n";
        }
        else
        {
            cout << shortestDistance[i] << "\n";
        }
    }
}