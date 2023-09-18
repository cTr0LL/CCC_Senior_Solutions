#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string letter,num,code;
    vector<pair<string,string>> decode;
    for(int i =0;i<n;i++)
    {
        cin>>letter>>num;
        decode.push_back({letter,num});
    }
    cin>>code;
    string ans;
    string current="";
    for(int i =0;i<code.length();i++)
    {
        current+=code[i];
        for(pair<string,string> c : decode)
        {
            if (c.second==current)
            {
                ans+=c.first;
                current="";
            } 
        }
    }
    cout<<ans;
}