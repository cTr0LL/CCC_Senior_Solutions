#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int ifriends;cin>>ifriends;
    int rounds;cin>>rounds;
    vector<int>elim;
    for(int i =0;i<rounds;i++)
    {
        int itemp;cin>>itemp;
        elim.push_back(itemp);
    }
    vector<int> friends;
    for(int i =1;i<=ifriends;i++)
        friends.push_back(i);
    vector<int>temp;
    for(int i =0;i<rounds;i++)
    {
        for(int j=0;j<friends.size();j++)
        {
            if((j+1)%elim[i]!=0)
                temp.push_back(friends[j]);
        }
        friends=temp;
        temp.clear();
    }
    for(int i =0;i<friends.size();i++)
        cout<<friends[i]<<endl;
}