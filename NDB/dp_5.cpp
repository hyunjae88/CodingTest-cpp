#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int N, M;
    vector<int> money;
    int input;

    cin >> N >> M;

    vector<int> dp(M+1, 10001);
    dp[0] = 0;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        money.push_back(input);
    }

    sort(money.begin(), money.end());

    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = money[i] ; j <= M ; ++j)
        {
            if(dp[j-money[i]] != 10001)
            {
                dp[j] = min(dp[j],dp[j-money[i]] + 1);
            }
        }
    }

    if(dp[M] == 10001)
    {
        cout << -1;
    }
    else
    {
        cout << dp[M];
    }


    return 0;
}