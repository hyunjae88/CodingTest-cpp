#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> list;
    int input;

    cin >> N;

    list.reserve(N);

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        list.emplace_back(input);
    }

    sort(list.begin(), list.end());

    int cnt     = 0;
    int result  = 0;

    for(const int& elem : list)
    {
        ++cnt;
        if(cnt >= elem)
        {
            ++result;
            cnt = 0;
        }
    }

    cout << result;
    
    return 0;
}