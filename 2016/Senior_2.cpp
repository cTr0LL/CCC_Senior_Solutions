#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int question;cin>>question;
    int n;cin>>n;
    vector<int>d;
    vector<int>p;
    int ans=0;
    for(int i =0;i<n;i++)
    {
        int temp;cin>>temp;
        d.push_back(temp);
    }
    for(int i =0;i<n;i++)
    {
        int temp;cin>>temp;
        p.push_back(temp);
    }
    if(question==1)///minimum
    {
        sort(d.begin(),d.end());
        sort(p.begin(),p.end());
        for(int i =0;i<n;i++)
        {
            ans+=max(p[i],d[i]);
        }
        cout<<ans;
    }
    else///maximum
    {
        sort(d.begin(),d.end());
        sort(p.begin(),p.end(),greater<int>());
        for(int i =0;i<n;i++)
        {
            ans+=max(p[i],d[i]);
        }
        cout<<ans;
    }
}