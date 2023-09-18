#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string lines;
    getline(cin,lines);
    int line=stoi(lines);
    int t=0;
    int s=0;
    for(int i =0;i<line;i++)
    {
        string sentence;
        getline(cin,sentence);
        for(int i =0;i<sentence.length();i++)
        {
            t+=(count(sentence.begin(),sentence.end(),'t')+count(sentence.begin(),sentence.end(),'T'));
            s+=(count(sentence.begin(),sentence.end(),'s')+count(sentence.begin(),sentence.end(),'S'));
        }
    }
    if(t>s)
        cout<<"English";
    else
        cout<<"French";
}