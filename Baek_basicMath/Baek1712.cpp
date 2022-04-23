#include <iostream>

using namespace std;

int main()
{
    int inputFixCost;
    int inputAddCost;
    int priceLaptop;
    int numOfSales = 0;

    cin >> inputFixCost >> inputAddCost >> priceLaptop;
    
    if(inputAddCost >= priceLaptop)
    {
        numOfSales = -1;
    }
    else
    {
        numOfSales = inputFixCost / (priceLaptop - inputAddCost);

        ++numOfSales;
    }

    cout << numOfSales;

    return 0;
}
