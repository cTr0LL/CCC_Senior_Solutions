#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]>grid[0][1]&&grid[0][0]>grid[1][0])///top left is the biggest
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    else if(grid[n-1][0]>grid[n-1][1]&&grid[n-1][0]>grid[n-2][0])///bot left
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
                cout<<grid[j][i]<<" ";
            cout<<endl;
        }
            
    }
    else if(grid[0][n-1]>grid[0][n-2]&&grid[0][n-1]>grid[1][n-1])///top right
    {
        for(int i =0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
                cout<<grid[j][i]<<" ";
            cout<<endl;
        }
    }
    else///bot right
    {
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }

}