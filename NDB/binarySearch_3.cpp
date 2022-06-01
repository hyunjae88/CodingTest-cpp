#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;

int getCuttingResult(const deque<int>& myQ, int mid)
{
    int result = 0;
    
    for(const int length : myQ)
    {
        if(length > mid)
        {
            result += (length - mid);
        }
    }

    return result;
}

int binarySearch(const deque<int>& myQ, int start, int end)
{
    int mid     = 0;
    int result  = 0;

    while(start <= end)
    {
        mid = (end + start) / 2;

        if(getCuttingResult(myQ, mid) < M)
        {
            end = mid - 1;
        }
        else
        {
            result = mid;
            start = mid + 1;
        }
    }
    
    return result;
}

int main()
{
    int tempInput;
    int max = 0;
    deque<int> myQueue;
    int result;

    cin >> N >> M;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> tempInput;
        if(tempInput > max)
        {
            max = tempInput;
        }
        myQueue.push_back(tempInput);
    }

    // cout << "max : " << max << endl;

    result = binarySearch(myQueue, 0, max);

    cout << result << endl;
    

    return 0;
}