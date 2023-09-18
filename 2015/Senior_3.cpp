#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numGates;cin>>numGates;
    set<int> gates;
    int count=0;
    for(int i =1;i<=numGates;i++)
        gates.insert(i);
    int numPlane;cin>>numPlane;
    vector<int>planes(numPlane);
    for(int i =0;i<numPlane;i++)
    {
        cin>>planes[i];
    }
    for(int i =0;i<numPlane;i++)
    {
        int plane=planes[i];
        auto it=gates.upper_bound(plane);
        if(it==gates.begin())
            break;
        else
        {
            gates.erase(*prev(it));
            count++;
        }
    }
    cout<<count;
}
