#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int numOfWood;cin>>numOfWood;
    vector<int>numOfWoodOfEachLength(2001);
    vector<int>comb(4001);///index is the height of the fence and the value is how many there can be of it
    for(int i =0;i<numOfWood;i++)
    {
        int temp;
        cin>>temp;
        numOfWoodOfEachLength[temp]++;
    }
    int longestLength=0,times=0;
    for(int i =1;i<=2000;i++)
    {
        if(numOfWoodOfEachLength[i]==0)
            continue;
        for(int j=i;j<2001;j++)///j is the height of the wood
        {
            if(numOfWoodOfEachLength[j]==0)
                continue;
            if(j==i)
                comb[j*2]+=numOfWoodOfEachLength[j]/2;                
            else
                comb[j+i]+=min(numOfWoodOfEachLength[j],numOfWoodOfEachLength[i]);
        }
    }
    for(int i =1;i<4001;i++)
    {
        if(comb[i]>longestLength)
        {
            longestLength=comb[i];
            times=1;
        }
        else if (comb[i]==longestLength)
            times++;
    }
    cout<<longestLength<<" "<<times;
}