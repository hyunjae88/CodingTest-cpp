#include <iostream>
#include <queue>

using namespace std;

int DP[12] = {0};

void solve(int nInput)
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    for(int i = 4 ; i <= nInput ; ++i)
    {
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
        //cout << DP[i] << endl;
    }
}

int main()
{
    int N = 0;

    cin >> N;

    queue<int> queueOutput;

    int nInput = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> nInput;
        solve(nInput);
        queueOutput.push(DP[nInput]);
    }

    for(int i = 0 ; i < N ; ++i)
    {
        cout << queueOutput.front() << "\n";
        queueOutput.pop();
    }

}