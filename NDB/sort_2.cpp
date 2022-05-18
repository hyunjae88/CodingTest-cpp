#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool compareRecord(pair<string, int> input1, pair<string, int> input2)
{
    if(input1.second < input2.second)
    {
        return true;
    }

    return false;
}

int main()
{
    int N = 0;
    string name("");
    int record = 0;
    deque<pair<string, int>> myDeque;

    cin >> N;

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> name;
        cin >> record;
        myDeque.push_back(make_pair(name, record));
    }

    sort(myDeque.begin(), myDeque.end(), compareRecord);

    for(pair<string, int>& student : myDeque)
    {
        cout << student.first << " ";
    }

    return 0;
}