#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int outcomes=0;
int team;
void predictions(int,vector<int>,vector<int>);
int main()
{
    cin>>team;
    int played;cin>>played;
    int team1,team2,score1,score2;
    vector<int>scores={0,0,0,0};
    vector<int>matches={12,13,14,23,24,34};
    for(int i =0;i<played;i++)
    {
        cin>>team1>>team2>>score1>>score2;
        matches.erase(remove(matches.begin(), matches.end(), team1*10+team2), matches.end());   
        if(score1>score2)
            scores[team1-1]+=3;
        else if(score1<score2)
            scores[team2-1]+=3;
        else
        {
            scores[team1-1]++;
            scores[team2-1]++;
        }
    }
    int remain=matches.size();
    vector<int>temp=scores;
    predictions(remain,matches,temp);
    cout<<outcomes;
}

void predictions(int remain,vector<int> matches,vector<int>score)
{
    if(remain==1)
    {
        int team1=matches[0]/10;
        int team2=matches[0]%10;
        score[team1-1]+=3;
        if(*max_element(score.begin(),score.end())==score[team-1]&&count(score.begin(),score.end(),*max_element(score.begin(),score.end()))==1)
            outcomes++;
        score[team1-1]-=3;
        score[team2-1]+=3;
        if(*max_element(score.begin(),score.end())==score[team-1]&&count(score.begin(),score.end(),*max_element(score.begin(),score.end()))==1)
            outcomes++;
        score[team2-1]-=2;
        score[team1-1]+=1;
        if(*max_element(score.begin(),score.end())==score[team-1]&&count(score.begin(),score.end(),*max_element(score.begin(),score.end()))==1)
            outcomes++;
    }
    else{
        
        remain--;
        int team1=matches[0]/10;
        int team2=matches[0]%10;
        score[team1-1]+=3;
        vector<int> temp;
        for(int i =1;i<matches.size();i++)
            temp.push_back(matches[i]);
        predictions(remain,temp,score);
        score[team1-1]-=3;
        score[team2-1]+=3;
        predictions(remain,temp,score);
        score[team2-1]-=2;
        score[team1-1]++;
        predictions(remain,temp,score);
    }
}