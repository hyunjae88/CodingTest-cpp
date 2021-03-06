#include <iostream>
#include <memory>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nInput = 0;
    const int nMax = 10001;
    cin >> nInput;

    //auto list = make_unique<int []>(nInput+10);
    int list[nMax] = {0};
    auto nNumber = 0;
    for(auto i = 0 ; i < nInput ; ++i)
    {
        cin >> nNumber;
        list[nNumber]++;
    }

    for(int i = 1 ; i < nMax ; i++)
    {
        for(int j = 0 ; j < list[i] ; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}