#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N, K;

    cin >> N;
    cin >> K;

    int input = 0;
    deque<int> A;
    deque<int> B;

    for(int i = 0 ; i < N ; ++i)
    {
       cin >> input;
       A.push_back(input);
    }

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        B.push_back(input);
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    for(int i = 0 ; i < K ; ++i)
    {
        if(A.at(i) < B.at(i))
        {
            swap(A[i], B[i]);
        }
        else
        {
            break;
        }
    }

    int sum = 0;
    for(const int& el : A)
    {
        sum += el;
    }

    cout << sum;

    return 0;
}