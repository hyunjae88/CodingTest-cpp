#include <iostream>

using namespace std;

int DP[12];

int solve(int n)
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for(int i = 4 ; i < n ; ++i)
    {
        DP[i] = DP[i-1]+2;
    }
}

int main()
{
    int T = 0;
    int n = 0;
    cin >> T;

    for(int i = 0 ; i < T ; ++i)
    {
        cin >> n;
        cout << solve(n) << endl;
    }

}