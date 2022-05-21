#include <iostream>
#include <deque>

using namespace std;

constexpr int kMAX_MAP = 20;
int N, M, startX, startY, cmdNumber;
int map[kMAX_MAP][kMAX_MAP];
deque<int> cmdSet;
int dice[7] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void printDice()
{
    for(int i = 1 ; i < 7; ++i)
    {
        cout << dice[i] << " ";
    }
    cout << endl;
}

void rollDice(int cmd)
{
    int d1, d2, d3, d4, d5, d6;
    d1 = dice[1];
    d2 = dice[2];
    d3 = dice[3];
    d4 = dice[4];
    d5 = dice[5];
    d6 = dice[6];

    switch(cmd)
    {
        case 0:
            {
                dice[1] = d4;
                dice[4] = d6;
                dice[3] = d1;
                dice[6] = d3;
            }
            break;
        case 1:
            {
                dice[1] = d3;
                dice[3] = d6;
                dice[6] = d4;
                dice[4] = d1;
            }
            break;
        case 2:
            {
                dice[1] = d5;
                dice[5] = d6;
                dice[6] = d2;
                dice[2] = d1;
            }
            break;
        case 3:
            {
                dice[1] = d2;
                dice[2] = d6;
                dice[6] = d5;
                dice[5] = d1;
            }
            break;
        default:
            break;
    }

    // printDice();
}

void solution()
{
    int x = startX;
    int y = startY;
    int nX = -1;
    int nY = -1;

    for(const int& cmd : cmdSet)
    {
        nX = x + dx[cmd];
        nY = y + dy[cmd];

        if(nX < 0 || nY < 0 || nX >= N || nY >= M)
        {
            continue;
        }

        rollDice(cmd);

        if(map[nX][nY] == 0)
        {
            map[nX][nY] = dice[6];
        }
        else{
            dice[6] = map[nX][nY];
            map[nX][nY] = 0;
        }

        cout << dice[1] << "\n";

        x = nX;
        y = nY;

    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> startX >> startY >> cmdNumber;

    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < M ; ++j)
        {
            cin>>map[i][j];
        }
    }

    int cmd = 0;
    for(int i = 0 ; i < cmdNumber ; ++i)
    {
        cin >> cmd;
        cmdSet.push_back(cmd-1);
    }

    solution();

    return 0;
}



// #include<iostream>
// #include<vector>
 
// #define endl "\n"
// #define MAX 20
// using namespace std;
 
// int N, M, Sx, Sy, K;
// int MAP[MAX][MAX];
 
// int dx[] = { 0, 0, -1, 1 };
// int dy[] = { 1, -1, 0, 0 };
 
// int Dice[7] = { 0 };
 
// vector<int> Cmd;

// void printDice()
// {
//     for(int i = 1 ; i < 7; ++i)
//     {
//         cout << Dice[i] << " ";
//     }
//     cout << endl;
// }
 
// void Input()
// {
//     cin >> N >> M >> Sx >> Sy >> K;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             cin >> MAP[i][j];
//         }
//     }
//     for (int i = 0; i < K; i++)
//     {
//         int a; cin >> a;
//         a = a - 1;
//         Cmd.push_back(a);
//     }
// }
 
// void RollTheDice(int d)
// {
//     int d1, d2, d3, d4, d5, d6;
//     d1 = Dice[1], d2 = Dice[2], d3 = Dice[3];
//     d4 = Dice[4], d5 = Dice[5], d6 = Dice[6];
 
//     if (d == 0)
//     {
//         Dice[1] = d4;
//         Dice[4] = d6;
//         Dice[6] = d3;
//         Dice[3] = d1;
//     }
//     else if (d == 1)
//     {
//         Dice[4] = d1;
//         Dice[6] = d4;
//         Dice[3] = d6;
//         Dice[1] = d3;
//     }
//     else if (d == 2)
//     {
//         Dice[1] = d5;
//         Dice[2] = d1;
//         Dice[6] = d2;
//         Dice[5] = d6;
//     }
//     else if (d == 3)
//     {
//         Dice[5] = d1;
//         Dice[1] = d2;
//         Dice[2] = d6;
//         Dice[6] = d5;
//     }

//     printDice();
// }
 
// void Solution()
// {
//     int x = Sx;
//     int y = Sy;
 
//     for (int i = 0; i < Cmd.size(); i++)
//     {
//         int nx = x + dx[Cmd.at(i)];
//         int ny = y + dy[Cmd.at(i)];
//         int d = Cmd.at(i);
 
//         if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        
//         RollTheDice(d);
//         if (MAP[nx][ny] == 0) MAP[nx][ny] = Dice[6];
//         else
//         {
//             Dice[6] = MAP[nx][ny];
//             MAP[nx][ny] = 0;
//         }
 
//         cout << Dice[1] << endl;
 
//         x = nx;
//         y = ny;
//     }
// }
 
// void Solve()
// {
//     Input();
//     Solution();
// }
 
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
 
//     //freopen("Input.txt", "r", stdin);
//     Solve();
 
//     return 0;
// }
