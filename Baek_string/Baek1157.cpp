/*
 * 백준 온라인 저지
 * 문제 제목 : 단어 공부
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int r = 0;
    string str = "";
    string strNew = "";

    cin >> str;

    for(char& c : str)
    {
        if(c >= 'a')
        {
            c-= 32;
        }
    }

    char cResult;
    auto nResultCnt = 0;
    auto bDeuce = false;

    for (char& c : str)
    {
        if(strNew.find(c) == string::npos)
        {
            strNew += c;
            int nTempCnt = 0;
            for(char& c2 : str)
            {
                if(c==c2)
                {
                    nTempCnt++;
                }
            }
            if(nResultCnt < nTempCnt)
            {
                nResultCnt = nTempCnt;
                cResult = c;
                bDeuce = false;
            }
            else if(nResultCnt == nTempCnt)
            {
                bDeuce = true;
            }
        }
    }

    if(bDeuce == true)
    {
        cout << "?" << endl;
    }
    else{
        cout << cResult << endl;
        //cout << strNew << endl;
    }
    
    return 0;
}