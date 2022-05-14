#include <iostream>
#include <memory>

using namespace std;

/*
 *
 * [문제 풀이]
 * N, M, K 외 둘째 줄에 N개의 자연수가 입력 받아 제일 큰 수와 두번 째 큰 수를
 * 찾아야 한다.
 * 입력 받은 수를 저장한 후 정렬해도 되지만 입력을 받을 때
 * 제일 큰 수와 두번 째로 큰 수를 찾아도 된다.
 * 이렇게 찾은 후 M과 K 로직을 적용하였다.
 * 
 */
int main()
{
    int N = 0;
    int M = 0;
    int K = 0;

    cin >> N >> M >> K;

    // auto inputArray = make_unique<int[]>(N);
    // for(int i = 0 ; i < N ; ++i)
    // {
    //     cin >> inputArray[i];
    // }
    
    int input       = 0;
    int first    = 0;
    int second = 0;
    int sum         = 0;
    bool isFirstFlag = true;
    int inputKCnt   = 0;

    //입력을 받자마자 가장 큰 수와 두번 째로 큰수를 구하는 반복문
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> input;
        if(input >= first)
        {
            second = first;
            first = input;
        }
        else if(input >= second)
        {
            second = input;
        }
        else{}
    }
    

    // cout << bigInput << " " << secondInput << endl;

    //방법1 입력 받은 변수 M과 K의 규칙을 적용하여 숫자를 합하는 반복문
    // for(int i = 0 ; i < M ; ++i)
    // {
    //     if(isFirstFlag)
    //     {
    //         sum += first;
    //         if(++inputKCnt == K)
    //         {
    //             isFirstFlag = !isFirstFlag;
    //             inputKCnt = 0;
    //         }
    //     }
    //     else{
    //         sum += second;
    //         isFirstFlag = !isFirstFlag;
    //     }
    // }

    //방법2 가장 큰 수와 두번 째 큰 수가 더해지는 횟수를 미리 계산하여 적용하는 방법
    int firstCnt = int(M/(K+1)) * K;
    firstCnt += M % (K+1);

    sum = firstCnt * first;
    sum += (M - firstCnt) * second;

    cout << sum << endl;

    return 0;
}