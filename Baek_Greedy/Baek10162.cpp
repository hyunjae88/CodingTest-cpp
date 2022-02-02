#include <iostream>

using namespace std;

int main()
{
    int nInput = 0;
    int nCnt = 0;

    cin >> nInput;

    if((nInput % 10) > 0){
        nCnt = -1;
        return 0;
    }

    nCnt = nInput / 300;
    nInput = nInput % 300;

    cout << nCnt << " ";

    nCnt = nInput / 60;
    nInput = nInput % 60;

    cout << nCnt << " ";

    nCnt = nInput / 10;

    cout << nCnt;

    return 0;

}