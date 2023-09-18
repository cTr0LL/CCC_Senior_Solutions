#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string year;
    cin>>year;
    if(stoi(year)<10)
    {
        int temp=stoi(year);
        temp++;
        cout<<temp;
        return 0;
    }
    bool state=true;
    while(state==true)
    {
        int iyear=stoi(year);
        iyear++;
        year=to_string(iyear);
        string temp=year;
        sort(temp.begin(),temp.end());
        for(int i =1;i<temp.length();i++)
        {
            if(i==temp.length()-1&&temp[i]!=temp[i-1])
                state=false;
            else if(temp[i]==temp[i-1])
                break;
        }
    }
    cout<<year;
}