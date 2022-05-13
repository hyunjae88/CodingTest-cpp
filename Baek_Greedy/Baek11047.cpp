#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int cost;
    int coin;
    int cnt = 0;

    vector<int> v;

    cin >> N >> cost;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> coin;
        v.push_back(coin);
    }

    // while(!v.empty())
    // {
    //     cnt += cost / v.back();
    //     cost = cost % v.back();
    //     v.pop_back();
    // }

    for(auto it = v.rbegin() ; it != v.rend() ; ++it)
    {
        cnt += cost / *it;
        cost = cost % *it;
    }

    cout << cnt << endl;

    return 0;
}