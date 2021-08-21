#include <iostream>

using namespace std;

int main()
{
    int N;
    int DP[5000] = {0};

    cin >> N;

    DP[3] = 1;
    DP[5] = 1;

    for(int i = 6 ; i <= N ; ++i)
    {
        if(DP[i-3])
        {
            DP[i] = DP[i-3] + 1;
        }
        if(DP[i-5]){
            if(DP[i]){
                DP[i] = min(DP[i], DP[i-5]+1);
            }
            else{
                DP[i] = DP[i-5]+1;
            }
        }
    }
    // for(int i = 0 ; i < N ; )
    if(DP[N] == 0){
        DP[N] = -1;
    }
    cout << DP[N] << endl;

    return 0;
}