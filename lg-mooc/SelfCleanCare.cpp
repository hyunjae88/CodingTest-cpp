#include <iostream>
using namespace std;

int y[110];
int x[110];
int N;
int L;
int M;
int sol;

void Input(void){
	cin >> N >> L >> M;
	for(int i = 0 ; i < M ; i++)
		cin >> y[i] >> x[i];
}

int count(int r, int c, int h, int w)
{
	int i, cnt = 0;
	for(i = 0 ; i < M ; i++)
	{
		if((r <= y[i]) && (y[i] <= h) && (c <= x[i]) && (x[i] <= w)) cnt++;
	}
	return cnt;
}

int Solve(void)
{
	int h, w, r, c, maxv = 0, cnt , k = L/2;
	for(h = 1 ; h < k ; h++)
	{
		w = k-h;
		for(r = 0 ; r < M ; r++)
		{
			for(c = 0 ; c < M ; c++)
			{
				cnt = count(y[r], x[c], y[r]+h, x[c]+w);
				if(maxv < cnt) maxv = cnt;
			}
		}
	}
	return maxv;
}

int main() {
	Input();
	
	sol = Solve();
	
	cout << sol;
}