#include <iostream>

using namespace std;

int N;
int B;
char S[100];
char D[100];
char Answer[10000] = {0};

void InputData()
{
    cin >> B >> S >> D;
}

int CharToInt(char in)
{
    int out;
    if(in >= '0' || in <= '9' )
    {
        out = (in -'0');
    }
    else if(in >= 'A' || in <= 'Z')
    {
        out = (in - 'A') + 10;
    }
    return out;
}

char IntToChar(int in)
{
    char out;

    if(in >= 0 || in <= 9)
    {
        out = in + '0';
    }
    else if(in >= 10 || in <= 36)
    {
        out = in + 'A';
    }
}

void Solve()
{
    int nS = 0;
    int nD = 0;
    int nUpResult = 0;
    int nResult = 0;
    int nMulti = 0;
    int nPos = 9999;

    for(int i = 99 ; i > 0 ; --i)
    {
        for(int j = 99 ; j > 0 ; --j)
        {
            nS = CharToInt(S[i]);
            nD = CharToInt(D[i]);
            nMulti = nS * nD;
            nResult = nMulti % B;
            nUpResult = nMulti / B;
            Answer[nPos--] += nResult;
            Answer[nPos] += nUpResult;
        }
    }

    for(int i = 9999 ; i > 0 ; --i)
    {
        if(Answer[i] > B)
        {
            Answer[i-1]++;
            Answer[i]-B;
        }
        Answer[i] = IntToChar(Answer[i]);
    }
}

int CharToDec[128];
char DecToChar[36];

void MakeLookUpTable()
{
    for(int i = 0 ; i < 10 ; ++i)
    {
        CharToDec['0'+i] = i;
        DecToChar[i] = '0' + i;
    }
    for(int i = 0 ; i < 26 ; ++i)
    {
        CharToDec['A'+i] = i + 10;
        DecToChar[i+10] = 'A' + i;
    }

    cout << CharToDec << endl;
    cout << DecToChar << endl;
}

int main()
{
    int i;
    cin >> N;

    MakeLookUpTable();


    for(i = 0 ; i < N; ++i)
    {
        InputData();

        Solve();
    }

    return 0;
}