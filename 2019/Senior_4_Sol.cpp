#include <bits/stdc++.h>
using namespace std;

void Solution()
{
   int N, K;
   cin >> N >> K;
   vector<int> atr(N);
   for (int i = 0; i < N; i++)
       cin >> atr[i];
   int day = (N + K - 1) / K;
   int minVisit = N % K;
   if (minVisit == 0)
       minVisit = K;
   vector<int> prefixMax(N, 0), suffixMax(N, 0);
   vector<long long> DP(N, 0), revDpMax(N, 0), revSumMax(N, 0);
   for (int i = 0; i < K; i++)
   {
       if (i > 0)
           prefixMax[i] = max(prefixMax[i - 1], atr[i]);
       else
           prefixMax[i] = atr[i];
       DP[i] = prefixMax[i];
   }
   for (int i = K - 1; i >= 0; i--)
   {
       if (i < K - 1)
           suffixMax[i] = max(suffixMax[i + 1], atr[i]);
       else
           suffixMax[i] = atr[i];
       revSumMax[i] = max(suffixMax[i] + (i > 0 ? DP[i - 1] : 0), (i < K - 1 ? revSumMax[i + 1] : 0));
       revDpMax[i] = max(DP[i], (i < K - 1 ? revDpMax[i + 1] : 0));
   }
   for (int d = 1; d < day; d++)
   {
       for (int i = K * d; i < min(N, K * (d + 1)); i++)
       {
           if (i > K * d)
               prefixMax[i] = max(prefixMax[i - 1], atr[i]);
           else
               prefixMax[i] = atr[i];
       }
       for (int i = min(N, K * (d + 1)) - 1; i >= K * d; i--)
       {
           if (i < min(N, K * (d + 1)) - 1)
               suffixMax[i] = max(suffixMax[i + 1], atr[i]);
           else
               suffixMax[i] = atr[i];
       }
       int it = K * (d - 1) + minVisit - 1;
       for (int i = it + K; i - it <= K && it < K * d && i < N; i++)
       {
           DP[i] = max(prefixMax[i] + revDpMax[it], revSumMax[it + 1]);
           it += (i - it == K);
       }
       for (int i = min(N, K * (d + 1)) - 1; i >= K * d; i--)
       {
           revSumMax[i] = max(suffixMax[i] + (i > 0 ? DP[i - 1] : 0), (i < min(N, K * (d + 1)) - 1 ? revSumMax[i + 1] : 0));
           revDpMax[i] = max(DP[i], (i < min(N, K * (d + 1)) - 1 ? revDpMax[i + 1] : 0));
       }
   }
   cout << DP[N - 1] << endl;
}
int main()
{
   Solution();
   return 0;
}