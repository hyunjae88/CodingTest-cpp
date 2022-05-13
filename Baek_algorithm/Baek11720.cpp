/*
 * 백준 온라인 저지
 * 문제 제목 : 숫자의 합
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numberCnt   = 0;
    string inputStr("");
    int result      = 0;

    cin >> numberCnt;
    cin >> inputStr;

    for(const char& c : inputStr)
    {
        result += (c-'0');
    }

    cout << result << endl;
    
    return 0;
}