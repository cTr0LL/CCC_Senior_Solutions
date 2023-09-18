#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

int main()
{
    int cases;cin>>cases;
    vector<string> answer;
    for(int z =0;z<cases;z++)
    {
        bool state=true;
        int cars;cin>>cars;
        stack<int>mountain;
        stack<int> branch;
        vector<int>lake={0};
        for(int i =0;i<cars;i++)
        {
            int temp;cin>>temp;
            mountain.push(temp);
        }
        while(lake.size()!=cars+1)
        {
            if(branch.empty()==false&&branch.top()==lake[lake.size()-1]+1)
            {
                lake.push_back(branch.top());
                branch.pop();
            }
            else if(mountain.empty()==false&&mountain.top()==lake[lake.size()-1]+1)
            {
                lake.push_back(mountain.top());
                mountain.pop();
            }
            else if(mountain.empty()==false)
            {
                branch.push(mountain.top());
                mountain.pop();
            }
            else
            {
                state=false;
                break;
            }
            if((lake.size()-1)!=lake[lake.size()-1])
            {    
                state=false;
                break;
            }
        }
        if(state)
            answer.push_back("Y");
        else
            answer.push_back("N");
    }
    for(int i =0;i<cases;i++)
        cout<<answer[i]<<endl;
}