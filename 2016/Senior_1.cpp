#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int difference(vector<int>original, vector<int>anagram)
{
    int diff=0;
    for(int i =0;i<26;i++)
    {
        diff+=abs(original[i]-anagram[i]);
    }
    return diff;
}

int main()
{
    vector<int> original={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> anagram={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string o;cin>>o;
    string a;cin>>a;
    for(int i =0;i<o.size();i++)
    {
        original[o[i]-'a']++;
    }
    int count=0;
    for(int i =0;i<o.size();i++)
    {
        if(a[i]=='*')
        {
            count++;
            continue;
        }
        anagram[a[i]-'a']++;
    }
    int diff=difference(original,anagram);
    if(diff==0)
        cout<<'A';
    else if(diff==count)
        cout<<"A";
    else
        cout<<"N";
    return 0;
}