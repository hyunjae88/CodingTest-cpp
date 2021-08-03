#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TextAndLength{
    unsigned short nLength = 0;
    string          str = "";
};

bool compare(const TextAndLength& input1, const TextAndLength& input2)
{
    if(input1.nLength > input2.nLength)
    {
        return true;
    }
    else if(input1.nLength == input2.nLength)
    {
        
        if(input1.str.compare(input2.str) > 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    auto nInput = 0;

    cin >> nInput;

    vector<TextAndLength> v;

    TextAndLength tal;

    for(auto i = 0 ; i < nInput ; ++i)
    {
        cin>>tal.str;
        tal.nLength = tal.str.length();
        v.push_back(tal);
    }

    sort(v.begin(), v.end(), compare);

    string strPre = "";
    for(auto i = 0 ; i < nInput ; ++i)
    {
        if(strPre != v.back().str)
        {
            strPre = v.back().str;
            cout << strPre << "\n"; 
        }
        v.pop_back();      
        
    }

    return 0;
}