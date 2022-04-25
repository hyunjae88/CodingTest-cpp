/*
 * 백준 온라인 저지
 * 문제 제목 : 그룹 단어 체커
 */

#include<iostream>
#include<string>
#include<memory>

using namespace std;

bool isGroupWord(string &str)
{
    bool bRtn = true;

    uint16_t index = 0;
    
    for(char& c : str)
    {
        if(index == str.length()-1)
        {
            break;
        }
        if(c != str.at(index+1))
        {
            if(str.find(c, index+1) != string::npos)
            {
                bRtn = false;
            }
        }
        index++;
    }

    return bRtn;
}

int main()
{
    int inputNum = 0;
    size_t result = 0;

    cin >> inputNum;

    auto strSetArr = make_unique<string[]>(inputNum);

   // cout << "입력" << endl;
    for(int i = 0 ; i < inputNum ; ++i)
    {
        cin >> strSetArr[i];

        if(isGroupWord(strSetArr[i]))
        {
            result++;
        }
    }

    cout << result;

    return 0;
}