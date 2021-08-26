#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int cost;
    int a;

    vector<int> v;

    cin >> N >> cost;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> a;
        v.push_back(a);
    }

    int cnt = 0;

    while(!v.empty())
    {
        cnt += cost / v.back();
        cost = cost % v.back();
        v.pop_back();
    }

    cout << cnt << endl;


    return 0;
}