#include <iostream>

using namespace std;

constexpr int MAX = 10;

int N, M = 0;

int answer[MAX] = {0};
bool isUsed[MAX] = {false};

void backTrack(int level)
{
    if(level == M)
    {
        for(int i = 0 ; i < M ; ++i)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1 ; i <= N; ++i)
    {
        if(isUsed[i]) continue;
        
        isUsed[i] = true;
        answer[level] = i;
        backTrack(level + 1);
        isUsed[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    
    backTrack(0);
    return 0;
}