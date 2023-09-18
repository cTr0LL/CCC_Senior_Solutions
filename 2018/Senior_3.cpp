#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
pair<int,int> source;
int dy[]={0,0,-1,1};
int N;
int M;
int dx[]={1,-1,0,0};

bool check_Camera(int x,int y)
{
    for(int i = x-1;i>=0;i--)
    {
        if(grid[i][y]=='C')
            return false;
        if(grid[i][y]=='W')
            break;
    }
    for(int i = x+1;i<N;i++)
    {
        if(grid[i][y]=='C')
            return false;
        if(grid[i][y]=='W')
            break;
    }
    for(int j=y-1;j>=0;j--)
    {
        if(grid[x][j]=='C')
            return false;
        if(grid[x][j]=='W')
            break;
    }
    for(int j=y+1;j<M;j++)
    {
        if(grid[x][j]=='C')
            return false;
        if(grid[x][j]=='W')
            break;
    }
    return true;
}

int main()
{
    cin>>N;
    cin>>M;
    grid=vector<vector<char>>(N,vector<char>(M));
    for(int i =0;i<N;i++)
    {
        string temp;cin>>temp;
        for(int j =0;j<M;j++)
        {
            grid[i][j]=temp[j];
            if(temp[j]=='S')
                source={i,j};
        }
    }
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    vector<vector<int>> steps(N,vector<int>(M,-1));
    queue<pair<int,int>> q;
    visited[source.first][source.second]=true;
    q.push(source);
    if(check_Camera(source.first,source.second)==true)
    {
        int step=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i =0;i<size;i++)
            {
                pair<int,int> cur=q.front();q.pop();
                if(grid[cur.first][cur.second]=='.')
                    steps[cur.first][cur.second]=step;
                for(int d =0;d<4;d++)
                {
                    pair<int,int> next={cur.first+dx[d],cur.second+dy[d]};
                    if(visited[next.first][next.second])
                        continue;
                    char ch=grid[next.first][next.second];
                    while(!visited[next.first][next.second]&&ch!='W'&&ch!='C'&&ch!='.')
                    {
                        visited[next.first][next.second]=true;
                        if(ch=='L')
                            next.second--;
                        else if(ch=='R')
                            next.second++;
                        else if(ch=='U')
                            next.first--;
                        else if(ch=='D')
                            next.first++;
                        ch=grid[next.first][next.second];
                    }
                    if(visited[next.first][next.second])
                        continue;
                    visited[next.first][next.second]=true;
                    if((ch=='.')&&check_Camera(next.first,next.second))
                        q.push(next);
                }
            }
            step++;
        }
    }
    for(int i =0;i<N;i++)
    {
        for(int j =0;j<M;j++)
        {
            if(grid[i][j]=='.')
                cout<<steps[i][j]<<endl;
        }
    }
    return 0;
}