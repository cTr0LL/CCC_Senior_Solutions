#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>tides;
    for(int i =0;i<n;i++)
    {
        int temp;cin>>temp;
        tides.push_back(temp);
    }
    sort(tides.begin(),tides.end());
    vector<int>low_tides;
    for(int i =(n+1)/2-1;i>=0;i--)
        low_tides.push_back(tides[i]);
    tides={tides.begin()+low_tides.size(),tides.end()};
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            cout<<low_tides[0]<<" ";
            low_tides.erase(low_tides.begin());
        }
        else
        {
            cout<<tides[0]<<" ";
            tides.erase(tides.begin());
        }

    }
}