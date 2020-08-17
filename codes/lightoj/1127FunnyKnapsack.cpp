#include <bits/stdc++.h>
#include <map>
using namespace std;

long long int n, w;
long long int weights[35];
map<long long int, long long int> dp[35];

int backTrack(int nth, int sum)
{
    if (sum > w)
        return 0;
        
    if (nth >= n)
    {
        if (sum <= w)
            return 1;
    }

    if (dp[nth].count(sum))
        return dp[nth][sum];
    
    return dp[nth][sum] = backTrack(nth + 1, sum) + backTrack(nth + 1, sum + weights[nth]);
}

int main()
{
    int testCaseCount;
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %lld", &n, &w);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &weights[i]);
        }

        printf("Case %d: %lld\n", testCase, backTrack(0, 0));

        for(int i=0; i<35; i++)
            dp[i].clear();
    }
    return 0;
}