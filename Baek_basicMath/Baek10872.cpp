#include <iostream>

using namespace std;

int main()
{
    auto nNum = 0;
    auto nResult = 1;
    cin >> nNum;


    for(int i = 1 ; i <= nNum ; ++i)
    {
        nResult *= i;
    }

    cout << nResult;

    return 0;
}