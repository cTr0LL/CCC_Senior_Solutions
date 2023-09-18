#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long> Good_Sample(long long length, long long height, long long num_sample)
{
    vector<long long >ans;
    for(long long i =0;i<length;i++)
    {
        long long remain=length-i-1;/// how many digits are left after this digit
        long long cur=min(num_sample-remain,height);///how many i should be covering with this digit
        if(cur<=0)
            break;
        if(cur>i)
        {
            ans.push_back(min(height,i+1));
            cur=ans[i];
        }
        else
            ans.push_back(ans[i-cur]);
        num_sample-=cur;
    }
    if(num_sample==0&&(long long)ans.size()==length)
        return ans;
    return {-1};
}

int main()
{
    long long length;
    long long height;
    long long num_sample;
    cin>>length>>height>>num_sample;
    vector<long long> song;
    song=Good_Sample(length,height, num_sample);
    for(long long i =0;i<(long long)song.size();i++)
        cout<<song[i]<<" ";
}