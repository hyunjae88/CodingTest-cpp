#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

struct DataSet{
    int set_a;
    int set_b;
    int set_c;
    int set_result;
};

int DP[21][21][21] = {0};

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <=0){
        return 1;
    }

    if(a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }

    if((a < b) && (b < c)){
        if(DP[a][b][c] !=0 )
        {
            return DP[a][b][c];    
        }
        return DP[a][b][c] = (w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c));
    }

    if(DP[a][b][c] != 0)
    {
        return DP[a][b][c];
    }
    return DP[a][b][c] = (w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) -w(a-1, b-1, c-1));
    
}

list<DataSet> vec;

int InputData()
{
    int in_a, in_b, in_c;
    cin >> in_a >> in_b >> in_c;
    DataSet ds;

    if( (in_a==-1) && (in_b==-1) && (in_c==-1))
    {
        return 0;
    }
    else{
        ds.set_a = in_a;
        ds.set_b = in_b;
        ds.set_c = in_c;
        ds.set_result = w(in_a, in_b, in_c);
        vec.push_front(ds);
        return 1;
    }
}

int main()
{
    int nCnt = 0;
    while(InputData())
    {
        nCnt++;
    }

    for(int i = 0 ; i < nCnt ; ++i)
    {
        cout << "w(" << vec.back().set_a << ", " << vec.back().set_b << ", " << vec.back().set_c << ") = " << vec.back().set_result << "\n";
        vec.pop_back();
    }
    return 0;
}