#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>t1;
    int one=0;
    vector<int>t2;
    int two=0;
    int ans=0;
    for(int i =0;i<n;i++)
    {
        int temp;cin>>temp;
        t1.push_back(temp);
    }
    for(int i =0;i<n;i++)
    {
        int temp;cin>>temp;
        t2.push_back(temp);
    }
    for(int i =0;i<n;i++)
    {
        one+=t1[i];
        two+=t2[i];
        if(one==two)
            ans=i+1;
    }
    cout<<ans;
}