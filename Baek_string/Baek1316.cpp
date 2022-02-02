/*
 * 백준 온라인 저지
 * 문제 제목 : 그룹 단어 체커
 */

#include<iostream>
#include<string>
#include<memory>

using namespace std;

bool GroupWordCheck(string &str)
{
    bool bRtn = true;

    for(int i = 0 ; i < str.length()-1 ; ++i)
    {
        char c = str.at(i);

        //cout << c << endl;

        if(c != str.at(i+1))
        {
            if(str.find(c, i+1) != string::npos)
            {
                bRtn = false;
            }
        }
    }

    return bRtn;
}

int main()
{
    int nNum = 0;
    int nResult = 0;

    cin >> nNum;

    auto strSet = make_unique<string[]>(nNum);

   // cout << "입력" << endl;
    for(int i = 0 ; i < nNum ; ++i)
    {
        cin >> strSet[i];

        if(GroupWordCheck(strSet[i]))
        {
            nResult++;
        }
    }

    cout << nResult;

    return 0;
}