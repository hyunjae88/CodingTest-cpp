/*
 * 백준 온라인 저지
 * 문제 제목 : 문자열 반복
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    int nCnt = 0;
    cin >> nCnt;

    int r = 0;
    string s,p = "";

    for(int i = 0 ; i < nCnt ; ++i)
    {
        cin>> r >> s;

        for(int j = 0 ; j < s.length() ; ++j)
        {
            for(int k = 0 ; k < r ; ++k)
            {
                cout << s.at(j);
            }
        }
        cout << endl;
    }
    
    return 0;
}