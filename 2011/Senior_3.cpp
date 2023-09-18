#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<vector<bool>>base;

bool check(int,int,int);

int main()
{
    base= {
	{false, true, true, true, false},
	{false, false, true, false, false},
	{false, false, false, false, false},
	{false, false, false, false, false},
	{false, false, false, false, false},
};
    string nums;
    getline(cin,nums);
    int num=stoi(nums);
    for(int i =0;i<num;i++)
    {
        int mag,x,y;
        cin>>mag>>x>>y;
        cout << ((check(mag, x, y))? "crystal" : "empty") << endl;
    }
}


bool check(int mag, int x,int y)
{
    if(mag==1)
    {
        return base[y][x];
    }
    ///first check to see if it is in one of the box thats garanteed to be crystal
    if(y<pow(5,mag-1))
    {
        if(x<pow(5,mag-1)||x>=(pow(5,mag)-pow(5,mag-1)))
            return false;
        else
            return true;
    }
    else if(y<(pow(5,mag)-pow(5,mag-1)*3)&&y>=pow(5,mag-1))
    {
        if(x<(pow(5,mag)-pow(5,mag-1)*2)&&x>=(pow(5,mag-1)*2))
            return true;
        else if(x<pow(5,mag-1)||x>=pow(5,mag-1)*4)
            return false;
        else
        {
            int temp=pow(5,mag-1);
            return check(mag-1,x%temp,y-pow(5,mag-1));
        }
    }
    else if(y<pow(5,mag-1)*3&&y>=pow(5,mag-1)*2)
    {
        if(x<pow(5,mag-1)*3&&x>=pow(5,mag-1)*2)
        {
            int temp=pow(5,mag-1);
            return check(mag-1,x%temp,y-pow(5,mag-1)*2);
        }
    }
    return false;
}