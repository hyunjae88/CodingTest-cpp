#include <iostream>
#include <vector>

using namespace std;

vector<int> inventory;
vector<int> requests;

bool binarySearch(const int target, int start, int end)
{
    int mid = -1;

    while(start <= end)
    {
        mid = (end+start) / 2;

        if(target == inventory[mid])
        {
            return true;
        }
        else if(target > inventory[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

int main()
{
    int N, M;
    int input = 0;
    bool result = false;

    cin >> N;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        inventory.push_back(input);
    }

    sort(inventory.begin(), inventory.end());

    cin >> M;
    for(int i = 0 ; i < M ; ++i)
    {
        cin >> input;
        requests.push_back(input);
    }

    for(int i = 0 ; i < M ; ++i)
    {
        result = binarySearch(requests[i], 0, N-1);
        if(result)
        {
            cout << "yes ";
        }
        else
        {
            cout << "no ";
        }
    }

    return 0;
}