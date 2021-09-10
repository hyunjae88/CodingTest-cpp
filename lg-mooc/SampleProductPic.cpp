#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

#define ID_MAX 1000000001

int N;
struct st{
	int X, ID;
};

st A[50010];
vector<st> v;
vector<long long> idListVector;

void InputData()
{
	cin >> N;
	for(int i = 0 ; i < N ; ++i)
	{
		cin >> A[i].X >> A[i].ID;
		v.push_back(A[i]);
		if(idListVector.empty()) idListVector.push_back(A[i].ID);
		else{
			bool isFind = false;
			for(int j = 0 ; j < idListVector.size() ; ++j)
			{
				if(A[i].ID == idListVector[j])
				{
					isFind = true;
					break;
				}
			}
			if(!isFind) idListVector.push_back(A[i].ID);
		}
	}
}

bool compare(st in1, st in2)
{
	return in1.X < in2.X;
}

int main() {
	int ans = -1;
	
	InputData();
	
	sort(v.begin(), v.end(), compare);
	
	// for(int i = 0 ; i < v.size() ; ++i)
	// {
	// 	cout << v[i].X << " ";
	// }
	// cout << endl;
	
	for(int i = 0 ; i < idListVector.size() ; ++i)
	{
		cout << idListVector[i] << " ";
	}
	cout << endl;
	
	long long minDistance = numeric_limits<long long>::max();
	long long tempDistance = 0;
	long long localMaxDistance = numeric_limits<long long>::min();
	int findCnt = 0;
	
	for(int i = 0 ; i < N-1 ; ++i)
	{
		localMaxDistance = numeric_limits<long long>::min();
		findCnt = 1;
		for(int j = 0 ; j < idListVector.size() ; ++j)
		{
			if(v[i].ID == idListVector[j]) continue;
			
			long long findItemId = idListVector[j];
			tempDistance = 0;
			
			for(int k = i+1 ; k < N ; ++k)
			{
				if(v[k].ID == findItemId){
					tempDistance = v[k].X - v[i].X;
					findCnt++;
					break;
				}
			}
			if(tempDistance > localMaxDistance)
			{
				localMaxDistance = tempDistance;
			}
		}
		// cout << "localMaxDistance : " <<localMaxDistance << endl;
		
		if((localMaxDistance < minDistance) && (findCnt == idListVector.size()))
			minDistance = localMaxDistance;
	}
	
	ans = minDistance;
	cout << ans << endl;
	
	return 0;
}