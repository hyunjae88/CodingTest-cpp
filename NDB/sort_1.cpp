#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int N = 0;
  int input = 0;

  deque<int> myDeque;

  cin >> N;

  for(int i = 0 ; i < N ; ++i)
  {
    cin >> input;
    myDeque.push_back(input);
  }

  sort(myDeque.rbegin(), myDeque.rend());

  for(int n : myDeque)
  {
    cout << n << "\n";
  }
  
  return 0;
}