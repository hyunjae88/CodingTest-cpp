#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& vector, const int& target, const int& start, const int& end)
{
    int mid = -1;

    if(start > end)
    {
        return -1;
    }

    mid = (start+end) / 2;

    if(vector[mid] == target)
    {
        return mid;
    }
    else if(vector[mid] > target)
    {
        return binarySearch(vector, target, start, mid-1);
    }
    else
    {
        return binarySearch(vector, target, mid+1, end);
    }

    return -1;
}

int binarySearchLoop(const vector<int>& vector, const int& target, int start, int end)
{
    int mid = -1;

    while(start <= end)
    {
        mid = (start + end) / 2;

        if(vector[mid] == target)
        {
            return mid;
        }
        else if(vector[mid] > target)
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
    int N, target = 0;
    int input = 0;
    int result = -1;

    cin >> N;
    cin >> target;
    vector<int> myVector;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        myVector.push_back(input);
    }

    // sort(myVector.begin(), myVector.end());

    result = binarySearch(myVector, target, 0, N-1);

    if(result == -1)
    {
        cout << "No foiund" << endl;
    }
    else
    {
        cout << result + 1 << endl;
    }

    result = binarySearchLoop(myVector, target, 0, N-1);

    if(result == -1)
    {
        cout << "No foiund" << endl;
    }
    else
    {
        cout << result + 1 << endl;
    }

    return 0;
}