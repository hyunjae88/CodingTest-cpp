#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string input;
    queue<int> inputNumber;
    long long result = 0;       //최종 결과
    int       frontNumber = 0;  //queue에서 꺼낸 숫자

    cin >> input;
    for(const char& c : input)
    {
        inputNumber.push(c-'0');
    }

    result = inputNumber.front();
    inputNumber.pop();

    while(!inputNumber.empty())
    {
        frontNumber = inputNumber.front();
        inputNumber.pop();

        if(result * frontNumber > result + frontNumber)
        {
            result = result * frontNumber;
        }
        else
        {
            result = result + frontNumber;
        }
    }

    cout << result << endl;

    return 0;
}