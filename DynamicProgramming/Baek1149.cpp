#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int DP[1001][3] = {0,};
    int N = 0;
    cin >> N;

    int R, G, B = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> R >> G >> B;
        DP[i+1][0] = min(DP[i][1], DP[i][2]) + R;
        DP[i+1][1] = min(DP[i][0], DP[i][2]) + G;
        DP[i+1][2] = min(DP[i][0], DP[i][1]) + B;
    }

    cout << min(min(DP[N][0],DP[N][1]), DP[N][2]);

    return 0;
}