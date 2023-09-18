#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> numbers;
    vector<int>base;
    string code;
    cin>>code;
    int answer=0;
    for(int i =0;i<code.length()/2;i++)
    {
        numbers.push_back((int)(code[i*2])-48);
        if(code[i*2+1]=='I')
            base.push_back(1);
        else if(code[i*2+1]=='V')
            base.push_back(5);
        else if(code[i*2+1]=='X')
            base.push_back(10);
        else if(code[i*2+1]=='L')
            base.push_back(50);
        else if(code[i*2+1]=='C')
            base.push_back(100);
        else if(code[i*2+1]=='D')
            base.push_back(500);
        else if(code[i*2+1]=='M')
            base.push_back(1000);
    }
    for(int i =1;i<numbers.size();i++)
    {
        if(base[i]>base[i-1])
            answer-=numbers[i-1]*base[i-1];
        else
            answer+=numbers[i-1]*base[i-1];
    }
    answer+=numbers[numbers.size()-1]*base[base.size()-1];
    cout<<answer<<endl;
}