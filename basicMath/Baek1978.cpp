#include <iostream>
#include <memory>

using namespace std;

bool isPrimeNumber(int& nInput)
{
    auto nPrime = 0;

    cout << nInput << endl;

    if(nInput == 1)
    {
        return false;
    }

    for(int i = 1 ; i < nInput ; ++i)
    {
        if((nInput % i) == 0)
        {
            nPrime++;
        }
    }

    if(nPrime == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    auto nNum = 0;
    auto nNumOfPrimeNum = 0;
    cin >> nNum;

    auto nInput = make_unique<int[]>(nNum);

    for(int i = 0 ; i < nNum ; ++i)
    {
        cin >> nInput[i];
    }

    for(int i = 0 ; i < nNum ; ++i)
    {
        nNumOfPrimeNum += isPrimeNumber(nInput[i]);
    }

    cout << nNumOfPrimeNum;

    return 0;
}