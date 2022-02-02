#include <iostream>
<<<<<<< HEAD
#include <queue>

using namespace std;

struct RGBset{
    int way[3];
};

int main()
{
    queue<RGBset> qRGBCost;

    int N = 0;
    cin >> N;

    RGBset rgbSet;

    rgbSet.way[0] = 0;
    rgbSet.way[1] = 0;
    rgbSet.way[2] = 0;

    qRGBCost.push(rgbSet);

    int R, G, B;

    for(int i = 0 ; i < N ; ++i )
    {
        cin >> R >> G >> B;

        rgbSet.way[0] = min(qRGBCost.front().way[1],qRGBCost.front().way[2]) + R;
        rgbSet.way[1] = min(qRGBCost.front().way[0],qRGBCost.front().way[2]) + G;
        rgbSet.way[2] = min(qRGBCost.front().way[0],qRGBCost.front().way[1]) + B;
        qRGBCost.push(rgbSet);
        qRGBCost.pop();
    }

    cout << min(qRGBCost.front().way[0], min(qRGBCost.front().way[1], qRGBCost.front().way[2])) << endl;
=======
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int DP[1001][3] = {0,};
    int N = 0;
    cin >> N;

    int R, G, B = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> R >> G >> B;
        DP[i+1][0] = min(DP[i][1], DP[i][2]) + R;
        DP[i+1][1] = min(DP[i][0], DP[i][2]) + G;
        DP[i+1][2] = min(DP[i][0], DP[i][1]) + B;
    }

    cout << min(min(DP[N][0],DP[N][1]), DP[N][2]);
>>>>>>> af304c8d38c7f23338151761f04bd55c1774b087

    return 0;
}