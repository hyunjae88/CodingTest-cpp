#include <iostream>
#include <cmath>

using namespace std;

const int MAX_VALUE = 1000000;

int DP[1000001] = {0};
int N = 0;

void inputData()
{
    cin >> N;
}

void makeOne()
{
    DP[1] = 0;
    for(int i = 2 ; i <= N ; ++i){
        DP[i] = DP[i-1] + 1;

        if(i % 2 == 0){
            DP[i] = min(DP[i], DP[i/2]+1);
        }
        if(i % 3 == 0){
            DP[i] = min(DP[i], DP[i/3]+1);
        }
    }
}

int main()
{
    inputData();

    makeOne();

    cout << DP[N] << endl;

    return 0;
}


// int main()
// {
//     constexpr int kMax = 1000001;
//     int result[kMax] = {0};
//     int input = 0;
    
//     result[1] = 0;
//     result[2] = 1;
//     result[3] = 1;

//     for(int i = 4 ; i < kMax ; ++i)
//     {
//         if(i%6==0)
//         {
//             result[i] = min(min(result[i-1],result[i/2]),result[i/3])+1;
//         }
//         else if(i%3==0)
//         {
//             result[i] = min(result[i/3], result[i-1])+1;
//         }
//         else if(i%2==0)
//         {
//             result[i] = min(result[i/2], result[i-1])+1;
//         }
//         else{
//             result[i] = result[i-1] + 1;
//         }
//     }

//     cin >> input;

//     cout << result[input] << endl;
// }



