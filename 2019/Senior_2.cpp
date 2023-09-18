#include <bits/stdc++.h>
using namespace std;

vector<bool> primeNum(int n)
{
    vector<bool>prime(2*n+1); 
    fill(prime.begin(),prime.end(),true);
    for (int p=2; p*p<=2*n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=2*n; i += p) 
                prime[i] = false; 
        } 
    }
   return prime;
}



int main()
{
    int n;cin>>n;
    vector<string>ans(n);
    vector<int>numbers(n);
    int maxnum=0;
    for(int i =0;i<n;i++)
    {    
        int temp;cin>>temp;
        numbers[i]=temp;
        maxnum=max(temp,maxnum);        
    }
    vector<bool>primes=primeNum(maxnum);
    for(int i =0;i<n;i++)
    {
        if(primes[numbers[i]]==true)
        {
            ans[i].append(to_string(numbers[i])+" "+to_string(numbers[i]));
            continue;
        }
        for(int j=2;j<=numbers[i];j++)
        {
            if(primes[j]==true&&primes[2*numbers[i]-j]==true)
            {
                ans[i].append(to_string(j)+" "+to_string(2*numbers[i]-j));
                break;
            }
        }
    }
    for(int i =0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
    
}