#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int s;
    cin>>s;
    if(s<4)
        cout<<0;
    else
        cout<<(s-1)*(s-2)*(s-3)/6;
}