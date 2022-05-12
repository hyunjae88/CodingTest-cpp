#include <iostream>

using namespace std;

struct Pl{
    Pl(){
        nSamll = 0;
        nBig = -1;
    }
    int nSamll;
    int nBig;
};

Pl DP[4000000];

int main()
{
    Pl pl;
    int nIndex = 0;
    for(int i = 0 ; i < 2000; ++i)
    {
        for(int j = 0 ; j < 2000; ++j)
        {
            pl.nSamll = i;
            pl.nBig = j;
            nIndex = i*3+j*5;
            if(DP[nIndex].nBig != -1)  //DP에 기존 값이 있는 경우
            {
                if(DP[nIndex].nBig < pl.nBig)
                    DP[i*3+j*5] = pl;
            }
            else                        //DP에 값이 처음 입력되는 경우
            {  
                DP[i*3+j*5] = pl;
            }
            
        }
    }

    int N;
    cin >> N;

    cout << (DP[N].nSamll+DP[N].nBig) << endl;

    return 0;
}