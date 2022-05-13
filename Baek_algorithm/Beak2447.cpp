/*
 * 백준 온라인 저지
 * 문제 제목 : 별 찍기 -10
 */

#include <iostream>

using namespace std;

void drawStar(int x, int y, int size)
{
    // cout << x << " " << y << " " << size << "\n";
   if((x/size)%3==1 && (y/size)%3 == 1)
   {
       cout << " ";
   }
   else
   {
       if(size/3==0)
       {
           cout << "*";
       }
       else
       {
           drawStar(x,y,size/3);
       }
   }
}

int main()
{
    int num;
    cin >> num;
    
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            drawStar(i,j,num);
        }
        cout << "\n";
    }
    
    return 0;
}