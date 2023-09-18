#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int ans=0;
    for(int i =0;i<=n/4;i++)
    {
        if((n-i*4)%5==0)
            ans++;
    }
    cout<<ans;
}