#include <iostream>
#include <memory>

using namespace std;

bool isPrimeNumber(int& nInput)
{
    bool isNotPrime = false;

    //cout << nInput << endl;

    if(nInput == 1)
    {
        return false;
    }

    for(int i = 2 ; i < nInput ; ++i)
    {
        if((nInput % i) == 0)
        {
            isNotPrime = true;
            break;
        }
    }

    if(isNotPrime == true)
    {
        return false;
    }
    return true;
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