#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string>answers;
    vector<string> response;
    string lengths;
    getline(cin,lengths);
    int length=stoi(lengths);
    int mark=0;
    for(int i =0;i<length;i++)
    {
        string temp;
        getline(cin,temp);
        response.push_back(temp);
    }
    for(int i =0;i<length;i++)
    {
        string temp;
        getline(cin,temp);
        answers.push_back(temp);
    }
    for(int i =0;i<length;i++)
    {
        if(answers[i]==response[i])
            mark++;
    }
    cout<<mark;
}