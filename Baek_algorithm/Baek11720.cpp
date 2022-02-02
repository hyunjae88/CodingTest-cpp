/*
 * 백준 온라인 저지
 * 문제 제목 : 숫자의 합
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    int nCnt;

    cin >> nCnt;

    string str;

    cin >> str;

    int nResult = 0;

    for(int i = 0 ; i < nCnt ; ++i)
    {
        nResult += (str.at(i)-'0');
    }

    cout << nResult << endl;
    
    return 0;
}