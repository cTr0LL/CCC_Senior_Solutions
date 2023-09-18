#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int lim;
    cin>>lim;
    int num;
    cin>>num;
    vector<int>trains;
    int cuma=0;
    for(int i =0;i<num;i++)
    {
        int temp;
        cin>>temp;
        trains.push_back(temp);
    }
    for(int i =0;i<num;i++)
    {
        if(i<4)
            cuma+=trains[i];
        else{
            cuma+=trains[i];
            cuma-=trains[i-4];
        }
        if(cuma>lim)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<num;
}