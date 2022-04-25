/*
 * 백준 온라인 저지
 * 문제 제목 : 문자열 반복
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint16_t inputNum = 0;
    cin >> inputNum;

    uint16_t repeatNum = 0;
    string str = "";
    string result = "";

    for(uint16_t i = 0 ; i < inputNum ; ++i)
    {
        cin>> repeatNum >> str;
        result = "";
        for(char c : str)
        {
            for(int k = 0 ; k < repeatNum ; ++k)
            {
                result += c;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}