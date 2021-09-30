#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    vector<int> v;
    int N = 0;
    int element;

    cin >> N;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> element;
        v.push_back(element);
    }

    int minValueIndex = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        minValueIndex = i;
        for(int j = i+1 ; j < N ; ++j)
        {
            if(v[j] < v[minValueIndex])
                minValueIndex = j;
        }
        int temp = v[i];
        v[i] = v[minValueIndex];
        v[minValueIndex] = temp;
    }


    for(int i = 0 ; i < N ; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;




    return 0;
}