#include <bits/stdc++.h>
using namespace std;

int nletters[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};///the num of each letter in the needle;
int hletters[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unordered_set<size_t> permutations;
bool check();


bool check()
{
    for(int i =0;i<26;i++)
    {
        if(nletters[i]!=hletters[i])
            return false;
    }
    return true;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    /// getting needle 
    string sn;cin>>sn;
    char needle[sn.length()+1];
    strcpy(needle,sn.c_str());
    int n=sn.length();

    ///  getting haysack 
    string sh;cin>>sh;
    char haysack[sh.length()+1];
    strcpy(haysack,sh.c_str());
    int h=sh.length();
    if(h<n)
    {
        cout<<0;
        return 0;
    }

    /// occurance of each letter in the needle
    for(int i =0;i<n;i++)
        nletters[needle[i]-'a']++;
    for(int i =0;i<n;i++)
        hletters[haysack[i]-'a']++;
    if(check())
        permutations.insert(hash<string>{}(sh.substr(0,n)));
    for(int i =n;i<h;i++)
    {
        hletters[haysack[i-n]-'a']--;
        hletters[haysack[i]-'a']++;
        if(check())
        {
            permutations.insert(hash<string>{}(sh.substr(i-n+1,n)));
        }    
    }
    cout<<permutations.size();
}
