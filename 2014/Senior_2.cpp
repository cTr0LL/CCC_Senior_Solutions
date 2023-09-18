#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;cin>>n;
    map<string, string> pairs;
    vector<string> l1(n),l2(n);
    for(int i =0;i<n;i++)
    {
        string temp;
        cin>>temp;
        l1[i]=temp;
    }
    for(int i =0;i<n;i++)
    {
        string temp;
        cin>>temp;
        l2[i]=temp;
    }
    bool good=true;
    for(int i =0;i<n;i++)
    {
        if(l1[i]==l2[i])
            good=false;
        if(pairs.count(l1[i])&&pairs[l1[i]]!=l2[i])
            good =false;
        pairs[l1[i]]=l2[i];
        pairs[l2[i]]=l1[i];
    }
    if(good)
        cout<<"good"<<endl;
    else
        cout<<"bad";
}
