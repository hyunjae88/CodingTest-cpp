/*
 * 백준 온라인 저지
 * 문제 제목 : 알파벳 찾기
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    cin >> str;

    int alphabetCnt = 'A' - 'a';
    int findIndex = 0;

    for(int i = 0 ; i < alphabetCnt ; ++i)
    {
        findIndex = str.find('a'+i);
        cout << findIndex << " ";
    }   
}