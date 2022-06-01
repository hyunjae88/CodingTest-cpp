#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int DP[101];

int main()
{
    cin >> N;

    int input = 0;
    vector<int> inventoryVector;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        inventoryVector.push_back(input);
    }

    DP[0] = inventoryVector[0];
    DP[1] = max(inventoryVector[0], inventoryVector[1]);

    for(int i = 2 ; i <= N ; ++i)
    {
        DP[i] = max(DP[i-1], DP[i-2]+inventoryVector[i]);
    }

    cout << DP[N-1] << endl;
    
    return 0;
}