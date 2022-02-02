#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nTestNumber;
    int nInput = 0;
    cin >> nTestNumber;

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

    for(int i = 0 ; i < nTestNumber ; ++i)
    {  
        cin >> nInput;
        if(nInput == 0){
            vZero.push_back(1);
            vOne.push_back(0);
        }else if(nInput == 1){
            vZero.push_back(0);
            vOne.push_back(1);
        }else{
            vZero.push_back(fibo[nInput-1]);
            vOne.push_back(fibo[nInput]);
        }
    }

    for(int i = 0 ; i < nTestNumber ; ++i)
    {
        cout << vZero[i] << " " << vOne[i] << "\n";
    }

    return 0;
}