#include <bits/stdc++.h>
using namespace std;

long getScore(int,vector<vector<int>>);

int main()
{
    int num_friends;cin>>num_friends;
    vector<vector<int>> friends(num_friends,vector<int>(3));
    int high=0;
    int low=INT_MAX;
    for(int i =0;i<num_friends;i++)
    {
        cin>>friends[i][0];
        cin>>friends[i][1];
        cin>>friends[i][2];
        if(friends[i][0]>high)
            high=friends[i][0];
        if(friends[i][0]<low)
            low=friends[i][0];
    }
    int mid=0;
    long s=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        s=getScore(mid,friends);
        long sLeft=getScore(mid-1,friends);
        long sRight=getScore(mid+1,friends);
        if(s==sLeft||s==sRight)
            break;
        if(s<sLeft&&s<sRight)
            break;
        if(s<sLeft)
            low=mid+1;
        else if(s<sRight)
            high=mid-1;
    }
    cout<<s;
}

long getScore(int n,vector<vector<int>>friends)
{
    long ans=0;
    for(int i =0;i<friends.size();i++)
    {
        long walk=abs(n-friends[i][0])-friends[i][2];
        if(walk>0)
            ans+=walk*friends[i][1];
    }
    return ans;
}
