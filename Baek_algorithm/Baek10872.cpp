/*
 * 백준 온라인 저지
 * 문제 제목 : 팩토리얼
 * 
문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

출력
첫째 줄에 N!을 출력한다.
 */

#include <iostream>

using namespace std;

int factorial(int input, int result = 1)
{
    if(input == 0)
    {
        return result;
    }
    
    result *= input;
    input--;
    return factorial(input, result);
}

int main()
{
    int input = 0;
    
    cin >> input;
    cout << factorial(input) << endl;
    
    return 0;
}