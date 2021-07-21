/*
 * 코드업
 * 문제 제목 : 입체기동장치 생산공장
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DeviceIndex{
    int nDevice;
    int nIndex;
};

bool compareDeviceIndex(const DeviceIndex& x, const DeviceIndex& y)
{
    return x.nDevice > y.nDevice;
}

int main()
{
    int nNum = 0;
    cin >> nNum;

    DeviceIndex DI;

    vector<DeviceIndex> vList;

    for(int i = 0 ; i < nNum ; ++i)
    {
        cin >> DI.nDevice;
        cin >> DI.nIndex;
        vList.push_back(DI);
    }

    std::sort(vList.begin(), vList.end(), compareDeviceIndex);

    for(int i = 0 ; i < nNum ; ++i)
    {
        cout << vList.back().nDevice << " " << vList.back().nIndex << endl;
        vList.pop_back();
    }

    return 0;
}