#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>money;
    int sum=0;
    for(int i =0;i<n;i++)
    {
        int temp;cin>>temp;
        if(temp==0)
        {
            sum-=money.back();
            money.pop_back();
        }
        else
        {
            sum+=temp;
            money.push_back(temp);
        }
    }
    cout<<sum;
}