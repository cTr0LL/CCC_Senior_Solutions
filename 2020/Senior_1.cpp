#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<pair<double,double>>data;
    double t,c;
    for(int i =0;i<n;i++)
    {
        cin>>c>>t;
        data.push_back({c,t});
    }
    sort(data.begin(),data.end());
    pair<double,double> cur1=data[0];
    pair<double,double> cur2=data[1];
    double maxspd=abs(cur2.second-cur1.second)/(cur2.first-cur1.first);
    for(int i =2;i<n;i++)
    {
        cur1=cur2;
        cur2=data[i];
        maxspd=max(abs(cur2.second-cur1.second)/(cur2.first-cur1.first),maxspd);
    }
    cout<<maxspd;
}