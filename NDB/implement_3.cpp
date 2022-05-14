#include <iostream>
#include <string>

using namespace std;

int moveTypeCol[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int moveTypeRow[8] = {-2, -2, -1, 1, 2, 2, -1, 1};

bool isPossibleToMove(int index, int col, int row)
{
    if( (col + moveTypeCol[index]) < 1 || (col + moveTypeCol[index]) > 8)
    {
        return false;
    }

    if( (row + moveTypeRow[index] < 1 || (col + moveTypeRow[index]) > 8))
    {
        return false;
    }

    return true;
}

int main()
{
    string pos("");
    int col, row = 0;
    int resultCnt = 0;

    cin >> pos;
    col = pos.at(0)-'a'+1;
    row = pos.at(1)-'0';

    cout << "col : "  << col << " row : " << row << endl;

    for(int i = 0 ; i < 8 ; ++i)
    {
        if(isPossibleToMove(i, col, row))
        {
            ++resultCnt;
        }
    }

    cout << resultCnt;

    return 0;
}