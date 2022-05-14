#include <iostream>

using namespace std;

int main()
{
    int cost = 0;
    int change = 0;
    int cnt = 0;
    int coinUnits[6] = {500,100,50,10,5,1};

    cin >> cost;
    change = 1000-cost;

    for(const int& coinUnit : coinUnits)
    {
        cnt += change / coinUnit;
        change = change % coinUnit;
    }

    cout << cnt << endl;
    
    return 0;
}