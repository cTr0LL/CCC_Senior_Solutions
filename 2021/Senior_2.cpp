#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;cin>>m;
    int n;cin>>n;
    vector<int> rows(m,0);
    vector<int> column(n,0);
    int a;cin>>a;
    int ans=0;
    for(int i =0;i<a;i++)
    {
        char rc;cin>>rc;
        int x;cin>>x;
        if(rc=='R')
        {
            rows[x-1]=(rows[x-1]+1)%2;
        }
        else
            column[x-1]=(column[x-1]+1)%2;
    }
    int r=count(rows.begin(),rows.end(),1);
    int c=count(column.begin(),column.end(),1);
    ans=r*n+c*m-r*c*2;
    cout<<ans;
}