#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& input1, const string& input2)
{
    if(input1.length() > input2.length())
    {
        return true;
    }
    else if(input1.length() == input2.length())
    {
        
        if(input1.compare(input2) > 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int input = 0;
    vector<string> v;
    string str("");

    cin >> input;

    for(auto i = 0 ; i < input ; ++i)
    {
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);

    string strPre = "";
    for(auto i = 0 ; i < input ; ++i)
    {
        if(strPre != v.back())
        {
            strPre = v.back();
            cout << strPre << "\n"; 
        }
        v.pop_back();
    }

    return 0;
}


