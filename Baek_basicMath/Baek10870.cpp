#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    auto nInput = 0;

    int nF[20] = {0};
    nF[0] = 0;
    nF[1] = 1;

    cin >> nInput;

    if(nInput == 0)
        cout << 0;
    else if(nInput == 1)
        cout << 1;
    else{
        
        
        for(int i = 2 ; i <= nInput ; ++i)
        {
            nF[i] = nF[i-1] + nF[i-2];
        }
        cout << nF[nInput];
    }
    return 0;
}