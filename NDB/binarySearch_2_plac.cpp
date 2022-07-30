#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vInventory;
vector<int> vRequests;

bool binarySearch(const int& _target, const int& _start, const int& _end)
{
    int mid = -1;
    int start = _start;
    int end = _end;

    while(end > start)
    {
        mid = (start + end) / 2;

        if(vInventory[mid] == _target)
        {
            return true;
        }
        else if(vInventory[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main()
{
    
    int input;

    cin >> N;
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        vInventory.emplace_back(input);
    }

    cin >> M;
    for(int i = 0 ; i < M ; ++i)
    {
        cin >> input;
        vRequests.emplace_back(input);
    }

    


    return 0;
}