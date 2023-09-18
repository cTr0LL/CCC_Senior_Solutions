#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;cin>>n;
    vector<int>heights(n+1);
    vector<int>lengths(n);
    long double total=0;
    for(int i =0;i<=n;i++)
        cin>>heights[i];
    for(int i =0;i<n;i++)
    {
        cin>>lengths[i];
        total+=(double)(heights[i]+heights[i+1])/2*lengths[i];
    }
    cout<<fixed<<total;
}