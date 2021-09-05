#include <iostream>

using namespace std;

int N;
int R[11];
int P[11];

long long minDiff;
int minCnt = 0;

void InputData(void){
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> R[i] >> P[i];
    }
}

long long myABS(int a1, int a2)
{
    return 0;
}

void DFS(int nStart, int nCnt, long long multOfR, long long sumOfP)
{
    if(nCnt != 0)
    {
        long long diff = abs(multOfR - sumOfP);
        if( (diff < minDiff) || ((diff==minDiff) && (nCnt < minCnt)))
        {
            minDiff = diff;
            minCnt = nCnt;
        }
    }

    for(int i = nStart ; i <= N ; ++i)
    {
        DFS(i+1, nCnt+1, multOfR*R[i], sumOfP+P[i]);
    }
    
}


void Solve()
{
    minDiff = 1e6;

    DFS(1, 0, 1, 0);
}

int main()
{
    int ans = -1;
    InputData();

    Solve();

    ans = N-minCnt;

    cout << ans << endl;

    return 0;
}