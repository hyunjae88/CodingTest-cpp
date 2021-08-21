#include <iostream>

using namespace std;

long long DP[91] = {0};

void solve(int N)
{
    for(int i = 2 ; i <= N ; ++i)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }
}

int main()
{
    int N = 0;

    DP[0] = 0;
    DP[1] = 1;

    cin >> N;

    solve(N);

    cout << DP[N] << endl;

    return 0;
}