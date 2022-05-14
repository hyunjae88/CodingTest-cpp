#include <iostream>
#include <string>

using namespace std;

int cntThreeInHour()
{
    int cnt = 0;

    for(int i = 0 ; i < 60 ; ++i)
    {
        string str = to_string(i);
        if(str.find('3')!=string::npos)
        {
            ++cnt;
        }
    }

    return ((cnt * 60) + (60 - cnt)*cnt);
}

int main()
{
    int N;
    int cntInhour = cntThreeInHour();
    int cntThreeHour = 0;
    int result = 0;

    cin >> N;

    for(int i = 0 ; i <= N ; ++i)
    {
        string str = to_string(i);
        cout << "str : " << str << endl;
        if(str.find('3') != string::npos)
        {
            ++cntThreeHour;
        }
    }

    // cout << cntThreeHour << " " << cntInhour << endl;

    result += cntThreeHour * 60 * 60;
    result += (N+1-cntThreeHour) * cntInhour;
    cout << result;

    return 0;
}