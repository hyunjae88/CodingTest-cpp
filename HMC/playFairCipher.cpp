#include <iostream>
#include <string>
#include <vector>

using namespace std;

char key[5][5];
string message;
vector<pair<char, char>> msgPair;

int     inputRowIndex = 0;
int     inputColIndex = 0;

int nextPosition[5] = {1,2,3,4,0};

bool isThisInKey(const char& in)
{
    for(int i = 0 ; i < 5 ; ++i)
    {
        for(int j = 0 ; j < 5 ; ++j)
        {
            if(in == key[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

void findTheKey(const char& in, int& row, int& col)
{
    for(int i = 0 ; i < 5 ; ++i)
    {
        for(int j = 0 ; j < 5 ; ++j)
        {
            if(in == key[i][j])
            {
                row = i;
                col = j;
                break;
            }
        }
    }
}

void inputInKey(char in)
{
    key[inputRowIndex][inputColIndex] = in;
    if(inputColIndex == 4)
    {
        inputRowIndex++;
        inputColIndex = 0;
    }
    else{
        inputColIndex++;
    }
}

void makeMsgPair(string inMessage)
{
    bool isFirst = true;
    char first, second;

    for(const char& c : inMessage)
    {
        if(isFirst)
        {
            first = c;
            isFirst = !isFirst;
        }
        else{
            if(c == first)
            {
                if(first == 'X')
                {
                    second = 'Q';
                }
                else{
                    second = 'X';
                }
                msgPair.emplace_back(make_pair(first, second));
                first = c;
            }
            else{
                second = c;
                msgPair.emplace_back(make_pair(first, second));
                isFirst = !isFirst;
            }
        }
    }

    if(!isFirst)
    {
        second = 'X';
        msgPair.emplace_back(make_pair(first, second));
    }

    // for(pair<char, char> test : msgPair)
    // {
    //     cout << test.first << " " << test.second << endl;
    // }
}

int main()
{
    string  inputKey;
    string  solution("");

    cin >> message >> inputKey;

    //키를 키 배열에 입력
    for(const char& c : inputKey)
    {
        if(!isThisInKey(c))
        {
            inputInKey(c);
        }
    }

    //나머지 알파벳을 키 배열에 입력
    for(char i = 0 ; i < 26 ; ++i)
    {
        char alphabet = i + 'A';
        if(alphabet == 'J')
        {
            continue;
        }

        if(!isThisInKey(alphabet))
        {
            inputInKey(alphabet);
        }
        if(inputRowIndex > 4)
        {
            break;
        }
    }

    // for(int i = 0 ; i < 5 ; ++i)
    // {
    //     for(int j = 0 ; j < 5 ; ++j)
    //     {
    //         cout << key[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //메시지 쌍으로 묶기
    makeMsgPair(message);

    int firstRow, firstCol;
    int secondRow, secondCol;
    char firstSolution, secondSolution;

    for(pair<char, char> element : msgPair)
    {
        findTheKey(element.first, firstRow, firstCol);
        findTheKey(element.second, secondRow, secondCol);

        if(firstRow == secondRow)
        {
            firstSolution = key[firstRow][nextPosition[firstCol]];
            secondSolution = key[firstRow][nextPosition[secondCol]];
        }
        else if(firstCol == secondCol)
        {
            firstSolution = key[nextPosition[firstRow]][firstCol];
            secondSolution = key[nextPosition[secondRow]][secondCol];
        }
        else
        {
            firstSolution = key[firstRow][secondCol];
            secondSolution = key[secondRow][firstCol];
        }
        solution += firstSolution;
        solution += secondSolution;
    }

    cout << solution << endl;
    
}