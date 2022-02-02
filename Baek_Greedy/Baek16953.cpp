#include <iostream>

using namespace std;

int main()
{
    int a, b = 0;
    int ans = 0;
    cin >> a >> b;

    while(1){
        if(a > b)
        {
            ans = -1;
            break;
        }
        else if(a == b){
            ans++;
            break;
        }

        if(b%10 == 1){
            b /= 10;
        }
        else if(b%2 == 0){
            b /= 2;
        }
        else{
            ans = -1;
            break;
        }
        ans++;

    }

    cout << ans << endl;

    return 0;
}