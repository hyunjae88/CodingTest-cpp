/*
 * 백준 온라인 저지
 * 문제 제목 : 팩토리얼
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    cin >> str;

    int nAlphabetCnt = 'z' - 'a' + 1;
    int nFindIndex = 0;

    for(int i = 0 ; i < nAlphabetCnt ; ++i)
    {
        nFindIndex = str.find('a'+i);
        cout << nFindIndex << " ";
    }   
}