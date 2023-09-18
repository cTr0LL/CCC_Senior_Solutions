#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numSameGroup;cin>>numSameGroup;
    set<pair<string,string>> together;
    for(int i =0;i<numSameGroup;i++)
    {
        string a, b;
        cin >> a >> b;
        together.emplace(make_pair(min(a, b), max(a, b)));
    }
    int numSeparated;cin>>numSeparated;
    set<pair<string,string>> separate;
    for(int i =0;i<numSeparated;i++)
    {
        string a, b;
        cin >> a >> b;
        separate.emplace(make_pair(min(a, b), max(a, b)));
    }
    int numGroups;cin>>numGroups;
    int count=0;
    set<pair<string,string>> togetherviolated;
    set<pair<string,string>> separateviolated;
    for(int i =0;i<numGroups;i++)
    {
        vector<string>group(3);
        for(int i =0;i<3;i++)
            cin>>group[i];
        for(int i =0;i<3;i++)
        {
            for(int j=i+1;j<3;j++)
            {
                pair<string,string> p={min(group[i],group[j]),max(group[i],group[j])};
                togetherviolated.insert(p);
                if(separate.find(p)!=separate.end())
                    separateviolated.insert(p);
            }
        }
    }
    for(auto& it:together)
    {
        if(togetherviolated.find(it)==togetherviolated.end())
            count++;
    }
    for(auto& it:togetherviolated)
        cout<<it.first<<" "<<it.second<<endl;
    cout<<togetherviolated.size()<<"count";
    cout<<count;
    count+=separateviolated.size();
    cout<<count;
}