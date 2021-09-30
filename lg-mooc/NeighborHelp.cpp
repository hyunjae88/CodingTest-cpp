#include <iostream>
using namespace std;

int N;
int C[10];
int sol[10];
int box[] = {1,5,10,50,100,500,1000,3000,6000,12000};
int maxN[10];

void InputData()
{
	int i;
	cin >> N;
	for(i = 0 ; i < 10 ; i++)
	{
		cin >> C[i];
	}
}

void OutputData(int ans)
{
	int i;
	cout << ans << endl;
	for(i = 0 ; i < 10 ; i++)
	{
		cout << sol[i] << " ";
	}
	cout << endl;
}

int Solve()
{
	for(int i = 0 ; i < 9 ; ++i)
	{
		maxN[i] = box[i]*C[i];
		if(i>0)
		{
			maxN[i] += maxN[i-1];
		}
	}

	int ans = 0;
	for(int i = 9 ; i > 0 ; --i)
	{
		int cnt = 0;
		while(maxN[i-1] < N)
		{
			cnt++;
			N -= box[i];
		}
		sol[i] = cnt;
		ans += sol[i];
	}
	sol[0] = N;
	ans += sol[0];

	return ans;
}

int main() {
	int ans = -1;
	
	InputData();
	
	ans = Solve();
	
	OutputData(ans);
	
	return 0;
}