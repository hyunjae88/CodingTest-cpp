#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int nInput = 0; 
    cin >> nInput;

    int nBuilding[80000] = {0};

    for(int i = 0; i < nInput; ++i)
    {
        cin >> nBuilding[i];
    }

    long long nResult = 0;

    stack<int> s;

    int stack[80010];
    int sp = 0;
    for(int i = 0; i <nInput; ++i)
    {

        while(sp>0)
        {
            if(stack[sp] > nBuilding[i])
                break;
            sp--;
        }
        nResult += sp;
        stack[++sp] = nBuilding[i];
       
    }

    cout << nResult << endl;

    return 0;
}