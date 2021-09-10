#include <iostream>
#include <limits>

using namespace std;

int N;
int T;
int P[100000 + 10];
int S[100000 + 10];

long long PredictPos[100000+10];
long long RealPos[100000 + 10];

void InputData()
{
	cin >> N >> T;
	for(int i = 0 ; i < N ; ++i)
	{
		cin >> P[i] >> S[i];
	}
}

int Solve()
{
	//그룹 결성
	RealPos[N] = numeric_limits<long long>::max();
	for(int i = N-1 ; i >= 0 ; --i)
	{
		PredictPos[i] = P[i] + (long long)(T*S[i]);
		// cout << S[i+1] << "<- S[i+1]" << endl;
		if(S[i+1] != 0)
		{
			if(PredictPos[i] < RealPos[i+1])
			{
				RealPos[i] = PredictPos[i];
			}
			else
			{
				RealPos[i] = RealPos[i+1];
			}
		}
		else
		{
			RealPos[i] = PredictPos[i];
		}
		//cout << i << " : " << RealPos[i] << " ";
	}
	// cout << endl;
	// cout << "Real Pos : ";
	// for(int i = 0 ; i < N ; ++i)
	// {
	// 	cout << RealPos[i] << " ";
	// }
	// cout << endl;
	
	//그룹 수 확인
	
	int groupCnt = 1;
	int tempPos = RealPos[0];
	for(int i = 1 ; i < N ; ++i)
	{
		if(RealPos[i] != tempPos)
		{
			groupCnt++;
			tempPos = RealPos[i];
		}
	}
	
	return groupCnt; 
}

int main() {
	int ans = -1;
	
	InputData();
	
	ans = Solve();
	
	cout << ans << endl;
	return 0;
}