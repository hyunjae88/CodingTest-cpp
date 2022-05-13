#include <iostream>
#include <memory>
#include <deque>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//자료구조를 활용한 방법이지만 백준 사이트에서는 메모리 초과로 나옴

bool compare(const int& number1, const int& number2)
{
    return (number1 < number2 ? true : false);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input = 0;
    constexpr int nMax = 10001;
    cin >> input;

    deque<int> myDeque;
    int list[nMax] = {0};

    int number = 0;
    for(auto i = 0 ; i < input ; ++i)
    {
        cin >> number;
        myDeque.push_back(number);
    }

    sort(myDeque.begin(), myDeque.end(), compare);

    for (int& number : myDeque){
        cout << myDeque.front() << endl;
        myDeque.pop_front();
    }

    return 0;
}