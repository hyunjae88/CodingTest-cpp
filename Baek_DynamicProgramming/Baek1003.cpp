#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testNumber;
    int input = 0;
    cin >> testNumber;

    vector<int> vZero;
    vector<int> vOne;

    int fibo[41] = {0};
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i = 3 ; i <= 40 ; ++i)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    for(int i = 0 ; i < testNumber ; ++i)
    {  
        cin >> input;
        if(input == 0){
            vZero.push_back(1);
            vOne.push_back(0);
        }else if(input == 1){
            vZero.push_back(0);
            vOne.push_back(1);
        }else{
            vZero.push_back(fibo[input-1]);
            vOne.push_back(fibo[input]);
        }
    }

    for(int i = 0 ; i < testNumber ; ++i)
    {
        cout << vZero.at(i) << " " << vOne.at(i) << "\n";
    }

    return 0;
}