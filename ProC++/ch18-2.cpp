#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void process(const vector<int>& vec, function<void(int)> f)
{
    for(auto& i : vec)
    {
        f(i);
    }
}

void print(int num)
{
    cout << num << " ";
}

int main()
{
    vector<int> vec{ 0,1,2,3,4,5,6,7,8,9};

    process(vec, print);
    cout << endl;

    int sum = 0;
    process(vec, [&sum](int num){sum+=num;});
    cout << "sum = " << sum << endl;
    
    return 0;
}