#include <iostream>
#include <cmath>

using namespace std;

const int MAX_VALUE = 1000000;

int DP[1000001] = {0};
int N = 0;

void InputData()
{
    cin >> N;
}

void MakeOne()
{
    DP[1] = 0;
    for(int i = 2 ; i <= N ; ++i){
        DP[i] = DP[i-1] + 1;

        if(i % 2 == 0){
            DP[i] = min(DP[i], DP[i/2]+1);
        }
        if(i % 3 == 0){
            DP[i] = min(DP[i], DP[i/3]+1);
        }
    }
}

int main()
{
    InputData();

    MakeOne();

    cout << DP[N] << endl;

    return 0;
}