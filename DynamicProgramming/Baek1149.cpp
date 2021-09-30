#include <iostream>
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

    return 0;
}