#include <iostream>

using namespace std;

int N;
char A[10+2][10+2];

void InputData()
{
    cin >> N;
    for(int i = 0; i < N ; i++)
    {
        cin >> A[i];
    }
}

int solve()
{
    int ans = 0;

    int out[10] = {0};

    for(int i = 1 ; i < 10 ; ++i)
    {
        int minX = 11, minY = 11;
        int maxX = -1, maxY = -1; 
        for(int j = 0 ; j < N ; ++j)
        {
            for(int k = 0 ; k < N ; ++k)
            {
                if((A[j][k]-'0') == i)
                {
                    if(k > maxX)
                        maxX = k;
                    if(k < minX)
                        minX = k;
                    if(j > maxY)
                        maxY = j;
                    if(j < minY)
                        minY = j;
                }
            }
        }
        //cout << minY << minX << maxY << maxX << endl;
        
        if(minX == 11)  continue;
            
        out[i]++;
        
        for(int j = minY ; j <= maxY ; ++j)
        {
            for(int k = minX ; k <= maxX ; ++k)
            {
                if((A[j][k]-'0') != i)
                    out[(A[j][k]-'0')]++;
            }
        }
        
    }

    for(int i = 0 ; i < 10 ; ++i)
    {
        //cout << out[i] << "\n";
        if(out[i] == 1)
            ans++;
    }

    return ans;
}

int main()
{
    int ans = -1;
    InputData();

    ans = solve();

    cout << ans << endl;

    return 0;
}