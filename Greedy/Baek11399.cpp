#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int p1, int p2){
    return p1 < p2;
}

int main()
{
    int N = 0;
    int P = 0;
    int sum = 0;
    cin >> N;
    
    vector<int> v;
    
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> P;
        v.push_back(P);
    }

    sort(v.begin(), v.end(), compare);

    int sum2 = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        // sum += v[i] * (N-i);
        sum += v[i];
        sum2 += sum;
    }

    cout << sum2 << endl;

    return 0;
}