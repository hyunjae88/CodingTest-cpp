#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string str("");
    queue<string> myQ;

    while(true)
    {
        getline(cin, str);
        if(str=="")
            break;
        myQ.push(str);
    }

    while(!myQ.empty())
    {
        cout << myQ.front() << "\n";
        myQ.pop();
    }

    return 0;
}