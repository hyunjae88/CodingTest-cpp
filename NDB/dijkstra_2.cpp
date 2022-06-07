#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct DstData{
    int dst;
    int distance;
};

constexpr int kBigDec = numeric_limits<int>::max();
constexpr int kNodeMaxCnt = 100001;

int N, M;
int startNode;
vector<DstData> graph[kNodeMaxCnt];
vector<int>     shortestDistance(kNodeMaxCnt, kBigDec);

void dijkstra(int startNode)
{
    priority_queue<pair<int, int>> pq;

    pq.emplace(make_pair(0, startNode));
    shortestDistance[startNode] = 0;

    int checkingDistance = 0;
    int checkingNode = 0;
    int costDistance = 0;

    while(!pq.empty())
    {
        checkingDistance = -pq.top().first;
        checkingNode    = pq.top().second;
        pq.pop();

        if(shortestDistance[checkingNode] < checkingDistance)
        {
            continue;
        }

        for(DstData dstData : graph[checkingNode])
        {
            costDistance = checkingDistance + dstData.distance;
            if(costDistance < shortestDistance[dstData.dst])
            {
                shortestDistance[dstData.dst] = costDistance;
                pq.push(make_pair(-costDistance, dstData.dst));

            }   
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> startNode;

    int inputSrc = 0;
    DstData inputDstData;

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

    return 0;
}