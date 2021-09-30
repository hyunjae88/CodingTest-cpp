#include <iostream>

using namespace std;

int a[2][12];

int main()
{
    const int MOD = 1000000000;
    // int N = 0;

    // int DP[101][11] = {0,};

    // cin >> N;

    // for(int i = 1 ; i < 10 ; ++i)
    // {
    //     DP[1][i] = 1;
    // }
    
    // for(int i = 2 ; i <= N ; ++i)
    // {
    //     DP[i][0] = DP[i-1][1];
    //     for(int j = 1 ; j <= 9 ; ++j)
    //     {
    //         DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%MOD;
    //     }

    // }

    // int sum = 0;
    // for(int i = 0 ; i <= 9 ; ++i)
    // {
    //     sum += DP[N][i];
    // }

    // cout << (sum%MOD) << endl;

    int n, ans = 9;

    cin >> n;

    for(int i = 2 ; i < 11 ; ++i)
    {
        a[1][i] = 1;
    }

    for(int i = 2; i <= n ; ++i)
    {
        ans = 0;
        for(int j = 1; j < 11; j++) {
            a[i%2][j] = (a[(i-1)%2][j-1] + a[(i-1)%2][j+1]) % MOD;
            ans = (ans + a[i%2][j]) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
