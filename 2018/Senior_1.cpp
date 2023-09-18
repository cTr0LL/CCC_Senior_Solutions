#include <bits/stdc++.h>
using namespace std;

int main()
{
    int amount;cin>>amount;
    vector<int> houses(amount);
    for(int i =0;i<amount;i++)
    {
        int temp;cin>>houses[i];
    }
    sort(houses.begin(),houses.end());
    int ans=INT_MAX;
    for(int i =1;i<amount-1;i++)
    {
        if((houses[i+1]-houses[i-1])<ans)
            ans=houses[i+1]-houses[i-1];
    }
    cout<<ans;
}