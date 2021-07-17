/*
 * 백준 온라인 저지
 * 문제 제목 : 팩토리얼
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