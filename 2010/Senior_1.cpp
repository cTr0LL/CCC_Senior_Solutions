#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int depth=1;
    int c;cin>>c;
    for(int d =0;d<c;d++)
    {
        int row,column;
        cin>>row>>column;
        vector<vector<char>> grid(row,vector<char>(column));
        for(int i=0;i<row;i++)
        {
            for(int j = 0;j<column;j++)
            {
                cin>>grid[i][j];
            }
        }
    }
}