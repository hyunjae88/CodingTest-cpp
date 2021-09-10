#include <iostream>
#include <limits>
using namespace std;

struct XY{
	int x;
	int y;
};

int N;//도화지 크기
char A[10 + 2][10 + 2];//도화지 색정보
XY COLOR_xy[10][2];
int COLOR_CNT[10+2][10+2];


void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

void CheckBoundary(int i, int x, int y)
{
	if(x < COLOR_xy[i][0].x)
	{
		COLOR_xy[i][0].x = x;
	}
	if(y < COLOR_xy[i][0].y)
	{
		COLOR_xy[i][0].y = y;
	}
	
	if(x > COLOR_xy[i][1].x)
	{
		COLOR_xy[i][1].x = x;
	}
	if(y > COLOR_xy[i][1].y)
	{
		COLOR_xy[i][1].y = y;
	}
}

int main(){
	int ans = -1;
	InputData();//	입력 함수

	//rkr 
	for(int i = 1 ; i < 10 ; ++i)
	{
		COLOR_xy[i][0].x = COLOR_xy[i][0].y = numeric_limits<int>::max();
		COLOR_xy[i][1].x = COLOR_xy[i][1].y = numeric_limits<int>::min();
		
		for(int j = 0 ; j < N ; ++j)
		{
			for(int k = 0 ; k < N ; ++k)
			{
				if(i == (A[j][k] - '0'))
				{
					//cout << "i : " << i << ", j : " << j << ", k : " << k <<endl;
					CheckBoundary(i, j, k);
				}
			}
		}
	}
	
	// for(int i = 0 ; i < 10 ; ++i)
	// {
	// 	cout << " i : "<< i << " " << COLOR_xy[i][0].x << " " << COLOR_xy[i][0].y << " " << COLOR_xy[i][1].x << " " << COLOR_xy[i][1].y << endl;
	// }
	
	int maxCnt = numeric_limits<int>::min();
	int tempCnt = 0;
	for(int i = 0 ; i < N ; ++i)
	{
		for(int j = 0 ; j < N ; ++j)
		{
			tempCnt = 0;
			for(int k = 1 ; k <=9 ; ++k)
			{
				if(COLOR_xy[k][0].x == numeric_limits<int>::max())
				{
					// cout << "continue " << endl;
					continue;
				}
				
				if((i >= COLOR_xy[k][0].x) && (i <= COLOR_xy[k][1].x)){
					if((j >= COLOR_xy[k][0].y) && (j <= COLOR_xy[k][1].y)){
						tempCnt++;
					}
				}
			}
			if(maxCnt < tempCnt)
			{
				// cout << "maxCnt : " << tempCnt << endl;
				maxCnt = tempCnt;
			}
		}
	}
	
	ans = maxCnt;
	
	cout << ans << endl;//출력
	return 0;
}
