#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int count=0;
    int num_jersey;cin>>num_jersey;
    int num_ppl;cin>>num_ppl;
    vector<int>jersey={0};
    for(int i =0;i<num_jersey;i++)
    {
        string ssize;cin>>ssize;
        if(ssize=="M")
            jersey.push_back(2);
        else if(ssize=="S")
            jersey.push_back(1);
        else
            jersey.push_back(3);
    }
    for(int i =0;i<num_ppl;i++)
    {
        string ssize;
        int number;
        cin>>ssize>>number;
        int isize;
        if(ssize=="S")
            isize=1;
        else if(ssize=="M")
            isize=2;
        else if(ssize=="L")
            isize=3;
        if(jersey[number]>=isize)
        {
            count++;
            jersey[number]=0;
        }
    }
    cout<<count;
}