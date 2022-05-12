#include <iostream>

using namespace std;

int main()
{
    int nInput = 0;
    constexpr int nMaxHouse = 1000;
    int R[nMaxHouse+1] = {0};
    int G[nMaxHouse+1] = {0};
    int B[nMaxHouse+1] = {0};

    cin >> nInput;

    for(int i = 0 ; i < nInput ; ++i)
    {
        cin >> R[i] >> G[i] >> B[i];
    }

    int cost1 = R[0];
    int cost2 = G[0];
    int cost3 = B[0];

    int preCost1;
    int preCost2;
    int preCost3;

    for(int i = 1 ; i < nInput ; ++i)
    {
        preCost1 = cost1;
        preCost2 = cost2;
        preCost3 = cost3;
        cost1 = R[i] + min(preCost2, preCost3);
        cost2 = G[i] + min(preCost1, preCost3);
        cost3 = B[i] + min(preCost1, preCost2);
    }

    cout << min(cost1, min(cost2,cost3)) << endl;

    return 0;
}