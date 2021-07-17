/*
 * 백준 온라인 저지
 * 문제 제목 : 스택
 * 
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int    data;
    int    num;
    string cmd;
    stack<int> myStack;
    
    cin >> num;
    
    for(int i = 0 ; i < num ; i++)
    {
        cin >> cmd;
        if(cmd=="push")
        {
            cin >> data;
            myStack.push(data);
        }
        else if(cmd=="pop")
        {
            if(myStack.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << myStack.top() << endl;
                myStack.pop();
            }
        }
        else if(cmd=="size")
        {
            cout << myStack.size() << endl;
        }
        else if(cmd == "empty")
        {
            cout << myStack.empty() << endl;
        }
        else if(cmd == "top")
        {
            if(myStack.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << myStack.top() << endl;
            }
        }
    }
    
    return 0;
}