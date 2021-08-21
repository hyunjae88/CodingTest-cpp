#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N;
char map[110][110];

int myMap[110][110];

int solvMap[110][110];

void Input_Data()
{
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> map[i];
    }
}

int Solve()
{
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < N ; ++j)
        {
            myMap[i][j] = map[i][j] - '0';
            // cout << myMap[i][j] << " ";
        }
        // cout << "\n";
    }

    int sum1;
    int sum2;
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < N ; ++j)
        {
            if((i > 0) && (j > 0))
            {
                solvMap[i][j] = min(solvMap[i-1][j],solvMap[i][j-1])+myMap[i][j];
            }
            else if(i > 0)
            {
                solvMap[i][j] = solvMap[i-1][j] + myMap[i][j];
            }
            else if(j > 0)
            {
                solvMap[i][j] = solvMap[i][j-1] + myMap[i][j];
            }
        }
    }

    int ans = solvMap[N-1][N-1];
    return ans;
}

int visit[110][110] = {90000};

int BFS()
{
    for(int i = 0 ; i < 110 ; ++i)
    {
        for(int j = 0 ; j < 110 ; ++j)
        {
            visit[i][j] = 90000;
        }
    }

    pair<int, int> direction[4];
    direction[0] = make_pair(-1,0);
    direction[1] = make_pair(0,-1);
    direction[2] = make_pair(1,0);
    direction[3] = make_pair(0,1);

    queue< pair<int, int> > myQ;

    myQ.push(make_pair(0,0));
    visit[0][0] = 0;

    int row = 0;
    int column = 0;

    int n_row = 0;
    int n_column = 0;

    while(myQ.size())
    {
        row = myQ.front().first;
        column = myQ.front().second;
        //cout << row << column << endl;
        myQ.pop();
        for(int i = 0 ; i < 4 ; ++i)
        {
            n_row = row + direction[i].first;
            n_column = column + direction[i].second;

            if((n_row < 0) || (n_row >= N) || (n_column < 0) || (n_column >= N))
            {
                // cout << "skip" << "\n";
                continue;

            }
            // cout << n_row << " " << n_column << " " << endl;
            if(visit[n_row][n_column] > visit[row][column]+map[n_row][n_column]-'0')
            {
                visit[n_row][n_column] = visit[row][column] + map[n_row][n_column]-'0';
                
                myQ.push(make_pair(n_row, n_column));
            }   
        }
    }

    return visit[N-1][N-1];
}

int main()
{
    int ans = -1;

    Input_Data();

    ans = BFS();
    //ans = Solve();

    cout << ans << endl;

    return 0;
}