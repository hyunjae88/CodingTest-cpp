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
    int sumFinal = 0;
    cin >> N;
    
    vector<int> v;
    
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> P;
        v.push_back(P);
    }

    sort(v.begin(), v.end());

    for(const int p : v)
    {
        // sum += v[i] * (N-i);
        sum += p;
        sumFinal += sum;
    }

    cout << sumFinal << endl;

    return 0;
}