#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c;cin>>c;
    vector<int> ans(c,-1);
    for(int d =0;d<c;d++)
    {
        int row,column;
        cin>>row>>column;
        vector<vector<char>> grid(row,vector<char>(column));
        for(int i=0;i<row;i++)
        {
            for(int j = 0;j<column;j++)
                cin>>grid[i][j];
        }
        if((row==1)&(column==1))
        {
            ans[d]=1;
            continue;
        }
        set<pair<int,pair<int,int>>> pq;
        vector<vector<bool>> visited(row,vector<bool>(column,false));
        pq.insert({1,{0,0}});
        while(!pq.empty())
        {
            pair<int,pair<int,int>> temp=*pq.begin();
            int x=temp.second.first;
            int y = temp.second.second;
            pq.erase(pq.begin());
            if(grid[x][y]=='*')
                continue;
            if(x==row-1&&y==column-1)
            {
                ans[d]=temp.first;
                break;
            }
            if(visited[x][y]==true)
                continue;
            visited[x][y]=true;

            if(grid[x][y]=='+')
            {
                if(x<=row-2)
                    pq.insert({temp.first+1,{x+1,y}});
                if(y<=column-2)
                    pq.insert({temp.first+1,{x,y+1}});
                if(x-1>=0)
                    pq.insert({temp.first+1,{x-1,y}});
                if(y-1>=0)
                    pq.insert({temp.first+1,{x,y-1}});
            }
            else if(grid[x][y]=='-')
            {
                if(y<=column-2)
                    pq.insert({temp.first+1,{x,y+1}});
                if(y-1>=0)
                    pq.insert({temp.first+1,{x,y-1}});
            }
            else if(grid[x][y]=='|')
            {
                if(x<=row-2)
                    pq.insert({temp.first+1,{x+1,y}});
                if(x-1>=0)
                    pq.insert({temp.first+1,{x-1,y}});
            }
        }
    }
    for(int i =0;i<c;i++)
    {
        cout<<ans[i]<<endl;
    }
}