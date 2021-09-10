#include <iostream>
using namespace std;

int N, M;
int A[5000], B[5000], D[5000];
int Table[5000][5000];

void InputData(){
	int i;
	cin >> N >> M;
	for(i = 0 ; i < M; i++)
	{
		cin >> A[i] >> B[i] >> D[i];
		Table[B[i]][A[i]] = Table[A[i]][B[i]] = D[i];
	}
}

void PrintTable()
{
    for(int i = 1 ; i <= N ; ++i )
    {
        for(int j = 1 ; j <= N ; ++j)
        {
            cout << Table[i][j] << " ";
        }
        cout << "\n";
    }
}

int Solve()
{
	int tableDistance = 0;
	int newDistance = 0;
	
	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j = 1 ; j <= N ; ++j)
		{
			if((i!=j) && (Table[i][j]==0))
				Table[i][j] = 101;
		}
	}

    PrintTable();
	// cout << "test";
	for(int i = 1 ; i <= N ; ++i)
	{
		for(int j = 1 ; j <= N; ++j)
		{
			for(int k = 1 ; k <= N ; ++k)
			{
				newDistance = Table[i][k] + Table[k][j];
				if(newDistance < Table[i][j])
                {
                    Table[j][i] = Table[i][j] = newDistance;
                    // cout << "new" <<endl;
                }
					
			}
		}
	}

    PrintTable();
	
	int minDistance = 100*100;
	int maxDistance = 0;
	for(int i = 1 ; i <= N ; ++i)
	{
        maxDistance = 0;
		for(int j = 1 ; j <= N ; ++j)
		{
			if(Table[i][j] > maxDistance)
			{
				maxDistance = Table[i][j];
			}
		}
        cout << "MAx : " << maxDistance << endl;
		if(maxDistance <= minDistance)
		{
			minDistance = maxDistance;
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