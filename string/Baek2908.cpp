/*
 * 백준 온라인 저지
 * 문제 제목 : 상수
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string strN1;
    string strN2;
    string strNewN1("");
    string strNewN2("");

    cin >> strN1 >> strN2;

    //cout << "input : ";
    //cout << strN1 << " " << strN2 << endl;

    for(int i = 0 ; i < strN1.length() ; ++i)
    {
        strNewN1.insert(i, string(1, strN1.at(strN1.length()-1-i)));
        strNewN2.insert(i, string(1, strN2.at(strN2.length()-1-i)));
        
    }
    auto n1 = stoi(strNewN1);
    auto n2 = stoi(strNewN2);

    //cout << "reverse : ";
    //cout << strNewN1 << " " << strNewN2 << endl;

    if(n1 >= n2)
    {
        cout << n1 << endl;
    }
    else
    {  
        cout << n2 << endl;
    }

    return 0;    
}