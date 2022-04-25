/*
 * 백준 온라인 저지
 * 문제 제목 : 단어의 개수
 */

#include<iostream>
#include<string>


using namespace std;


int main()
{
	int spaceCnt = 0;
    string str;
    char space = ' ';

    getline(cin, str);

    if(str.empty())
    {
        cout << "0";
        return 0;
    }

    for(size_t i = 0 ; i < str.length() ; ++i)
    {
        if(str.at(i) == space)
        {
            spaceCnt++;
        }
      }
    
    if(str[0] == space)
        spaceCnt--;
    if(str[str.length()-1] == space)
        spaceCnt--;

    cout << spaceCnt + 1 << endl;

    return 0;
}