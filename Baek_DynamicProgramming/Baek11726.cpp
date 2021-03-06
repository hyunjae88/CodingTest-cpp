#include <iostream>

using namespace std;

//https://kosaf04pyh.tistory.com/222 설명 참고

int DP[1010];

int main()
{
    int N;

    cin >> N;

    DP[1] = 1;
    DP[2] = 2;

    for(int i = 3 ; i <= N ; ++i)
    {
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }

    cout << DP[N] << endl;

    return 0;
}