/*
 * 백준 온라인 저지
 * 문제 제목 : 단어의 개수
 */

#include<iostream>
#include<string>


using namespace std;


int main()
{
	int nSpaceCnt = 0;
    int nFindPoint = 0;
    string str;
    string space = " ";

    getline(cin, str);

    if(str.empty())
    {
        cout << "0";
        return 0;
    }

  for(int i = 0 ; i < str.length() ; ++i)
  {
    if(str.at(i) == ' ')
    {
      nSpaceCnt++;
    }
  }
    
    if(str[0] == ' ')
        nSpaceCnt--;
    if(str[str.length()-1] == ' ')
        nSpaceCnt--;

    cout << nSpaceCnt + 1 << endl;

    return 0;
}