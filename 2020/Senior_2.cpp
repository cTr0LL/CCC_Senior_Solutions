#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int m,n;
int v;
bool isValid(int row,int col)
{
    if(row>=m||col>=n)
        return false;
    return true;
}

int main()
{
    cin>>m;
    cin>>n;
    vector<vector<int>> grid(m);
    vector<vector<bool>>visited(m);
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            visited[i].push_back(false);
            cin>>v;
            grid[i].push_back(v);
        }
    }
    queue<pair<int,int>> totest;totest.push({0,0});
    bool state=false;
    while(!state&&!totest.empty())
    {
        pair<int,int> val=totest.front();
        totest.pop();
        int row=val.first;
        int col=val.second;
        if(visited[row][col])
            continue;
        if(row==(m-1)&&col==(n-1))
        {
            state=true;
            continue;
        }
        visited[row][col]=true;
        int curval=grid[row][col];
        int sqrcurval=sqrt(curval);
        for(int i =1;i<=sqrcurval;i++)
        {
            if(curval%i==0)
            {
                int newRow=curval/i-1;
                int newCol=i-1;
                if(isValid(newRow,newCol)&&!visited[newRow][newCol])
                    totest.push({newRow,newCol});
                if(isValid(newCol,newRow)&&!visited[newCol][newRow])
                    totest.push({newCol,newRow});
            }
        }
    }
    if(state)
            cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}