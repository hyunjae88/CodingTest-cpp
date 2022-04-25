/*
 * 백준 온라인 저지
 * 문제 제목 : 상수
 */


#include <iostream>
#include <string>

using namespace std;

void reversingStr(string& str)
{
    string output("");
    for(char c : str)
    {
        output.insert(0, 1, c);
    }
    str = output;
}

int main()
{
    string strInput1("");
    string strInput2("");

    cin >> strInput1 >> strInput2;

    // since C++20
    // std::reverse(strInput1.begin(), strInput1.end());
    // std::reverse(strInput2.begin(), strInput2.end());

    // C++17
    reversingStr(strInput1);
    reversingStr(strInput2);

    auto reversedNumber1 = stoi(strInput1);
    auto reversedNumber2 = stoi(strInput2);

    cout << ((reversedNumber1 > reversedNumber2) ? reversedNumber1 : reversedNumber2) << endl;

    return 0;    
}