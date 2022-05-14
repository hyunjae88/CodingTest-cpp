#include <iostream>

using namespace std;

int main()
{
    int N, K = 0;
    int cnt = 0;

    cin >> N >> K;

    while(N != 1)
    {
        if(!(N % K))
        {
            N /= K;
        }
        else{
            N -= 1;
        }
        ++cnt;
    }

    cout << cnt;

    return 0;
}