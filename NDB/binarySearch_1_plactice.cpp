#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& _vNumbers, const int& _target, const int& _start, const int& _end)
{
    int mid = (_start + _end) / 2;

    if(_start > _end)
    {
        return -1;
    }

    if(_vNumbers[mid] == _target)
    {
        return mid;
    }
    else if(_vNumbers[mid] < _target)
    {
        return binarySearch(_vNumbers, _target, mid+1, _end);
    }
    else
    {
        return binarySearch(_vNumbers, _target, _start, mid-1);
    }

    return -1;
}

int binarySearchLoop(const vector<int>& _vNumbers, const int& _target, const int& _start, const int& _end)
{
    int start   = _start;
    int end     = _end;
    int mid = -1;

    while(start <= end)
    {
        mid = (start + end)/2;
        if(start > end)
        {
            return -1;
        }
        if(_vNumbers[mid] == _target)
        {
            return mid;
        }
        else if( _vNumbers[mid] > _target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int N, target;
    vector<int> vNumbers;
    int inputNumber;
    int result;

    cin >> N >> target;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> inputNumber;
        vNumbers.emplace_back(inputNumber);
    }

    sort(vNumbers.begin(), vNumbers.end());

    result = binarySearch(vNumbers, target, 0, N-1);

    if(result == -1)
    {
        cout << "No found" << endl;
    }
    else
    {
        cout << result+1 << endl;
    }

}