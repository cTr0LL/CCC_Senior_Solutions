#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ipt;cin>>ipt;
    vector<vector<int>>flip={{1,2},{3,4}};
    int h=0;
    int num=count(ipt.begin(),ipt.end(),'H');
    if(num%2==1)
        h=1;
    int v=ipt.length()-num;
    if(h==1)
    {
        vector<int>temp=flip[0];
        flip[0]=flip[1];
        flip[1]=temp;
    }
    if(v==1)
    {
        int one=flip[0][0];
        int two=flip[1][0];
        flip[0][0]=flip[0][1];
        flip[1][0]=flip[1][1];
        flip[0][1]=one;
        flip[1][1]=two;
    }
    cout<<flip[0][0]<<" "<<flip[0][1]<<endl<<flip[1][0]<<" "<<flip[1][1];
}