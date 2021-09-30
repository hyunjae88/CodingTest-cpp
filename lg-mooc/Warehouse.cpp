#include <iostream>
#include <limits>

using namespace std;

int N, M;
int A[5000], B[5000], D[5000];

int TABLE[101][101];
int MAX_VALUE[101];

void InputData()
{
    int i;
    cin >> N >> M;
    for(int i = 0 ; i < M ; ++i)
    {
        cin >> A[i] >> B[i] >> D[i];
    }
}

void FindData(int inI, int inJ)
{
    int minValue = (TABLE[inI][inJ]) ? TABLE[inI][inJ] : numeric_limits<int>::max();
    // int minValue = TABLE[inI][inJ];
    int tempValue = 0;
    for(int i = 1 ; i <= N ; ++i)
    {
        if( (i == inI) || (i == inJ)) continue;

        if((TABLE[inI][i] != 0) && (TABLE[i][inJ] != 0))
        {
            tempValue = TABLE[inI][i] + TABLE[i][inJ];
            if(tempValue < minValue)
                minValue = tempValue;
        }
       
    }

    TABLE[inJ][inI] = TABLE[inI][inJ] = minValue;
}

int Solve()
{
   
    // for(int i = 1 ; i <= N ; ++i)
    // {
    //     for(int j = 1 ; j <= N ; ++j)
    //     {
    //         if(i!=j) TABLE[i][j] = numeric_limits<int>::max();
    //         else
    //             TABLE[i][j] = 0;
    //     }
    // }

    for(int i = 0 ; i < M  ; ++i)
    {
        TABLE[B[i]][A[i]] = TABLE[A[i]][B[i]] = D[i];
    }

    // for(int i = 1 ; i <= N ; ++i)
    // {
    //     for(int j = 1 ; j <= N ; ++j)
    //     {
    //         cout << TABLE[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1 ; i <= N ; ++i)
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            if(i==j) continue;

            FindData(i,j);
        }
    }


    int minV = numeric_limits<int>::max();
    for(int i = 1 ; i <= N ; ++i)
    {  
        int maxV = 0;

        for(int j = 1 ; j <= N ; ++j)
        {
            if(TABLE[i][j] > maxV)
                maxV = TABLE[i][j];
        }
        
        if(maxV < minV)
            minV = maxV;
    }
    return minV;
}

int main()
{
    int ans = -1;
    InputData();

    ans = Solve();

    cout << ans <<endl;
    return 0;
}