#include <iostream>

using namespace std;

int N;
int S[100000 +10];

void InputData(){
    cin >> N;
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> S[i];
    }
}

int Solve()
{
    int nLength = 1;
    int nPast = S[0];
    int nCnt = 0;
    int nPattern[100000+10] = {0};

    for(int i = 1 ; i < N ; ++i)
    {
        if(S[i] != nPast){
            nLength++;
        }
        else{
            nPattern[nCnt++] = nLength;
            nLength = 1;
        }
        nPast = S[i];
    }

    nPattern[nCnt++] = nLength;

    int nMax = 0;
    int tmp = 0;
    for(int i = 1 ; i < nCnt-1 ; ++i)
    {
        tmp = nPattern[i-1] + nPattern[i] + nPattern[i+1];
        if( tmp > nMax)
        {
            nMax = tmp;
        }
            
    }

    return nMax;

    // int max = 0; 
    // int seq = 0;
    // for(int i = 0 ; i < 3 ; i++) seq += nPattern[i];
    // max = seq;
    // for(int i = 3 ; i < nCnt; i++)
    // {
    //     seq += nPattern[i] - nPattern[i-3];
    //     if(max < seq) max = seq;
    // }
    // return max;


}

int main()
{
    int ans = -1;

    InputData();

    ans = Solve();

    cout << ans << endl;

    return 0;
}