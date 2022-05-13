/*
 * 백준 온라인 저지
 * 문제 제목 : 스택
 */

#include <iostream>
#include <string>
#include <string_view>
#include <stack>

using namespace std;

void printEmptyError(){
    cout << -1 << endl;
}
void printTop(stack<int> const& _stack){
    cout << _stack.top() << endl;
}

void printPop(stack<int>& _stack){
    printTop(_stack);
    _stack.pop();
}

void printSize(stack<int> const& _stack){
    cout << _stack.size() << endl;
}

void printEmpty(stack<int> const& _stack){
    cout << _stack.empty() << endl;
}

int main()
{
    int    data;
    int    num = 0;;
    string cmd("");
    constexpr string_view kPush("push");
    constexpr string_view kPop("pop");
    constexpr string_view kSize("size");
    constexpr string_view kEmpty("empty");
    constexpr string_view kTop("top");

    stack<int> myStack;
    
    cin >> num;
    
    for(int i = 0 ; i < num ; ++i)
    {
        cin >> cmd;
        if(cmd==kPush)
        {
            cin >> data;
            myStack.push(data);
        }
        else if(cmd==kPop)
        {
            if(myStack.empty())
            {
                printEmptyError();
            }
            else
            {
                printPop(myStack);
            }
        }
        else if(cmd==kSize)
        {
            printSize(myStack);
        }
        else if(cmd == kEmpty)
        {
            printEmpty(myStack);
        }
        else if(cmd == kTop)
        {
            if(myStack.empty())
            {
                printEmptyError();
            }
            else
            {
                printTop(myStack);
            }
        }
    }
    
    return 0;
}