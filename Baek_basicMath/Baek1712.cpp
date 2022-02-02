#include <iostream>

using namespace std;

int main()
{
    int cost1, cost2, price;

    cin >> cost1 >> cost2 >> price;

    int nSales = 0;

    
    if(cost2 >= price)
    {
        nSales = -1;
    }
    else
    {
        nSales = cost1 / (price - cost2);

        ++nSales;
    }

    cout << nSales;

    return 0;
}