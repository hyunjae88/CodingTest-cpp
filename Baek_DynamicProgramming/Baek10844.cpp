#include <iostream>

using namespace std;

int DP[2][12];

int main()
{
    constexpr int kMOD = 1000000000;

    int n       = 0;
    int ans     = 9;

    cin >> n;

    for(int i = 2 ; i < 11 ; ++i)
    {
        DP[1][i] = 1;
    }

    for(int i = 2; i <= n ; ++i)
    {
        ans = 0;

        /*
         * 설명
         * 한 자리 숫자의 경우는 1 ~ 9
         * 두 자리 숫자의 경우는 0 ~ 9
         * 첫 번째 for문에서 한 자리 숫자에 대한 경우의 수를 1로 입력
         * DP[1][2] => 1이 나오는 경우
         * DP[1][1] => 0이 나오는 경우
         * DP[1][0] => 불가능한 경우를 0 초기값
         * DP[1][10] => 9가 나오는 경우
         * DP[1][11] => 불가능한 경우 0 초기값
         * 현재 2중 for문 중 밖에 for문은 자리수를 추가해 가면 더하는 것
         * 안에 for문은 현재 자리수에서 각 숫자로 올수 있는 경우의 수를 입력
         * 예를 들어 DP[3][4] 는 DP[2][3]의 경우 DP[2][5]에서 올 수 있음
         * DP[(i-1)%2][j-1]에서 (i-1)%2는 DP 배열의 공간을 절약하기 위함
         * 
         */
        for(int j = 1; j < 11; j++) {
            DP[i%2][j] = (DP[(i-1)%2][j-1] + DP[(i-1)%2][j+1]) % kMOD;
            ans = (ans + DP[i%2][j]) % kMOD;
        }
    }

    cout << ans << endl;
    return 0;
}
