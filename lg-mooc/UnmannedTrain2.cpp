#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
int M;
int map[50+10][50+10];

struct pos{
	int x;
	int y;
};

vector<pos> group1;
vector<pos> group2;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void InputData(void){
	cin >> N >> M;
	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = 1 ; j <= M ; j++)
		{
			cin >> map[i][j];
		}
	}
}

void FindGroup(int x, int y, int groupNumber)
{
	if(map[x][y] != 1) return;
	
    map[x][y] = 0;
	pos tempPos;
	tempPos.x = x;
	tempPos.y = y;
	
	if(groupNumber == 1)
	{
		group1.push_back(tempPos);
	}
	else if(groupNumber == 2)
	{
		group2.push_back(tempPos);
	}
	
	for(int i = 0 ; i < 4 ; ++i)
	{
		FindGroup(x+dx[i],y+dy[i], groupNumber);
	}
}

int Solve(void)
{
	int groupNumber = 1;
	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j = 1 ; j <= M ; ++j)
		{
            if(map[i][j] == 1)
            {
                FindGroup(i, j, groupNumber);
			    groupNumber++;
            }
			
		}
	}
	
	int minDistance = numeric_limits<int>::max();
	int distance = 0;
	
	for(int i = 0 ; i < group1.size() ; ++i)
	{
		for(int j = 0 ; j < group2.size() ; ++j)
		{
			distance = abs(group1[i].x - group2[j].x) + abs(group1[i].y - group2[j].y)-1;
			// cout << "Distance : " << distance << endl;
            if(distance < minDistance)
			{
                // cout << "minDistance : " << minDistance << endl;
				minDistance = distance;
			}
		}
	}
	return minDistance;
}

int main() {
	int ans = -1;
	InputData();
	
	ans = Solve();

	cout << ans << endl;
	
	return 0;
}