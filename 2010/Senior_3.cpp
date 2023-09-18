#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,c,k;
vector<int>houses;
int circumference=1000000;
int binarysearch(int min,int max);
bool check(int cover);

int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>c;
        houses.push_back(c);
    }
    sort(houses.begin(),houses.end());
    cin>>k;
    if (k>n)
    {
        cout<<0;
        return 0;
    }
    int ideal=binarysearch(0,circumference);
    while(check(ideal))
        ideal--;
    ideal++;
    cout<<ideal;
}

int binarysearch(int min, int max)
{
    if(max-1==min)
        return max;
    else
    {
        int mid=(min+max)/2;
        if(check(mid))
            return binarysearch(min,mid);
        else
            return binarysearch(mid,max);
    }
}

bool check(int cover)
{
    for(int i =0;i<n;i++)///the first hydrants left most place
    {
        int numHydrant=0;///how many hyrant have i used?
        int index=i;
        int covered=0;///how many houses have i covered?
        while(covered!=n)
        {
            int current=houses[index];///where is the current house
            numHydrant++;covered++;index++;index=index%n;///this makes index the next house
            while(covered!=n)
            {
                if(current+2*cover>=circumference)
                {
                    if ((current+2*cover)%circumference>=houses[index])
                    {
                        covered++;index++;index=index%n;
                    }
                    else
                        break;
                    
                }
                else{
                    if((current+2*cover)%circumference>=houses[index]&&houses[index]>=current)
                    {
                        covered++;index++;index=index%n;
                    }
                    else
                        break;
                }
            }
        }
        if(numHydrant<=k)
            return true;
    }
    return false;
}