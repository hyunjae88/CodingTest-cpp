#include <iostream>

using namespace std;

int main()
{
    int cost = 0;
    int change = 0;
    int cnt = 0;
    cin >> cost;
    change = 1000-cost;

    cnt += change / 500;
    change = change % 500;

    // cout << "cnt " << cnt << " change " << change << endl;

    cnt += change / 100;
    change = change%100;

    cnt += change / 50;
    change = change % 50;

    cnt += change / 10;
    change = change % 10;

    cnt += change / 5;
    change = change % 5;

    cnt += change / 1;
    change = change % 1;

    cout << cnt << endl;



    return 0;
}