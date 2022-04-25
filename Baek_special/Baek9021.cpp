#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool isVPS(string str)
{
    int num = 0;
    // cout << str.length() << endl;
    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(str[i] == '(')
        {
            // cout << "++";
            ++num;
        }
        else if(str[i] == ')')
        {
            //  cout << "--";
            --num;
        }
        if(num < 0)
            return false;
    }

    if(num != 0)
        return false;

    return true;
}

int main()
{
    int N = 0;
    cin >> N;

    string strInput;
    string strResult;
    queue<string> resultQ;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> strInput;
        if(isVPS(strInput))
            strResult = "YES";
        else
            strResult = "NO";
        
        resultQ.push(strResult);
    }

    for(int i = 0 ; i < N ; ++i)
    {
        cout << resultQ.front() << "\n";
        resultQ.pop();
    }

    return 0;
}