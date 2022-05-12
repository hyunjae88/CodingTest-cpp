#include <iostream>
#include <limits>

using namespace std;

int foo(int n)
{
    const int myMax         = n + 1000;
    constexpr int myMin         = n - 1000;

    cout << myMax << " " << myMin << endl;

    return (myMax - myMin);
}

int main()
{
    // const int mx = numeric_limits<char>::max();

    // int arr[mx];
    int input;

    cin >> input;
    
    cout << foo(input) << endl;

    return 0;
}