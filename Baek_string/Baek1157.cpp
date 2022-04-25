/*
 * 백준 온라인 저지
 * 문제 제목 : 단어 공부
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "";

    cin >> str;

    for(char& c : str)
    {
        if(c >= 'a')
        {
            c-= 32+'A';
        }
        else
        {
            c-= 'A';
        }
    }

    int     cntAlphabet[32] = {0};
    int     maxCnt      = 0;
    int     maxIndex    = -1;
    char    result;
    bool    bDeuce      = false;

    for(char& c : str)
    {
        ++cntAlphabet[c];
        if(cntAlphabet[c] > maxCnt)
        {
            maxCnt = cntAlphabet[c];
            bDeuce = false;
            maxIndex = c;
        }
        else if(cntAlphabet[c] == maxCnt)
        {
            bDeuce = true;
        }
    }

    if(bDeuce)
    {
        cout << "?" << endl;
    }
    else{
        result = maxIndex + 'A';
        cout << result << endl;
    }
    
    return 0;
}