#include <iostream>

using namespace std;

int main()
{
    int coinUnits[4] = {500, 100, 50, 10};
    int change  = 0;
    int coinCnt = 0;

    cin >> change;

    for(const int coinUnit : coinUnits)
    {
        coinCnt += (change / coinUnit);
        change %= coinUnit;
    }

    cout << coinCnt << endl;

    return 0;
}