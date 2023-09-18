#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

multimap<int, int> invert(map<int, int> & mymap)
{
	multimap<int, int> multiMap;

	map<int, int> :: iterator it;
	for (it=mymap.begin(); it!=mymap.end(); it++) 
		multiMap.insert(make_pair(it->second, it->first));
	return multiMap;
}



int main()
{
    map<int,int> values;///first one is the value, second one is occurence
    int num=0;
    cin>>num;
    for(int i =0;i<num;i++)
    {
        int temp;
        cin>>temp;
        values[temp]++;
    }
    multimap<int,int> v=invert(values);
    ///multimap<int,int>::iterator itr;
    vector<int>largest;///the numbers with the largest occurence
    int ilargest=0;///how many times
    vector<int>second;///the numbers with the second occurence
    int isecond=0;
    bool firstnum=true;
    bool secnum=false;
    for(auto itr=v.rbegin();itr!=v.rend();++itr)
    {
        int occur=itr->first;///occurance of this number
        int n=itr->second;///the number
        cout<<"key"<<n<<"value"<<occur<<endl;
        if(firstnum)
        {
            largest.push_back(n);
            ilargest=occur;
            firstnum=false;
            secnum=true;
        }
        else if (occur==ilargest)
            largest.push_back(n);
        else if(occur!=ilargest&&secnum==true)
        {
            if(occur<isecond)
                break;
            second.push_back(n);
            isecond=occur;
        }
    }
    if(largest.size()>1)
        cout<<*max_element(largest.begin(),largest.end())-*min_element(largest.begin(),largest.end());
    else{
        int large=largest[0];
        int maxdif=0;
        for(int i =0;i<second.size();i++)
        {
            cout<<second[i]<<"this is one"<<endl;
            if(abs(second[i]-large)>maxdif)
                maxdif=abs(second[i]-large);
        }
        cout<<large<<endl;
        cout<<maxdif;
    }
}
