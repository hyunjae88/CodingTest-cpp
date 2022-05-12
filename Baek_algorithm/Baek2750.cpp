#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main()
{
    auto nInput = 0;

    cin >> nInput;

    list<int> list;

    auto nNumber = 0;
    for(auto i = 0 ; i < nInput ; ++i)
    {
        cin >> nNumber;
        list.push_back(nNumber);
    }

    list.sort();

    for(auto i = 0 ; i < nInput ; ++i)
    {
        cout << list.front() << "\n";
        list.pop_front();
    }

    return 0;
}