#include <iostream>
#include <memory>
#include <limits>

using namespace std;

int main()
{
    int N, M = 0;
    int input = 0;
    int size = 0;
    int smallValueInRow = numeric_limits<int>::max();
    int columnCnt = 0;
    int result = numeric_limits<int>::min();

    cin >> N >> M;
    size = N * M;

    // 반복문 하나를 이용하는 방법
    // for(int i = 0; i < size ; ++i)
    // {
    //     cin >> input;
    //     if(input < smallValueInRow)
    //     {
    //         smallValueInRow = input;
    //     }

    //     if(++columnCnt == M)
    //     {
    //         if(smallValueInRow > result)
    //         {
    //             result = smallValueInRow;
    //         }
    //         columnCnt = 0;
    //         smallValueInRow = numeric_limits<int>::max();
    //     }
    // }

    //이중 반복문을 이용하는 방ㅈ법
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            cin >> input;
            if(input < smallValueInRow)
            {
                smallValueInRow = input;
            }
        }
        if(smallValueInRow > result)
        {
            result = smallValueInRow;
        }
        smallValueInRow = numeric_limits<int>::max();
    }

    cout << result;

    return 0;
}