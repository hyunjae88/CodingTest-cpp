#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> record;
vector<pair<int, int>> term;

float calcAverage(const int& start, const int& end)
{
    float sum         = 0;

    for(int  i = start-1 ; i <= end-1 ; ++i)
    {
        sum += (float)record[i];
    }

    return sum/(float)(end-start+1);
}

int main()
{
    cin >> N >> K;
    int inputRecord = 0;
    int inputStartRecord = 0;
    int inputEndRecord = 0;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> inputRecord;
        record.emplace_back(inputRecord);
    }

    // sort(record.begin(), record.end());

    for(int i = 0 ; i < K ; ++i)
    {
        cin >> inputStartRecord >> inputEndRecord;
        term.emplace_back(inputStartRecord, inputEndRecord);
    }

    cout << fixed;
    cout.precision(2);
    for(const pair<int, int>& elem : term)
    {
        cout << calcAverage(elem.first, elem.second) <<"\n";
    }

    return 0;
}