#include <bits/stdc++.h>
using namespace std;

int n, k, coins[110], quantity[110];
long long int answer;
long long int dp[110][1010];

long long int recurse(int index, int amount)
{
    if (index == n)
    {
        if (amount == k)
            return 1;
        else
            return 0;
    }

    long long int &ret = dp[index][amount];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int take = 0; take <= quantity[index]; take++)
    {
        if (amount + (coins[index] * take) <= k)
            ret = (ret + recurse(index + 1, amount + (coins[index] * take))) % 100000007;
        else
            break;
    }

    return ret;
}

int main()
{
    int testCaseCount;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));

        for (int coin = 0; coin < n; coin++)
            cin >> coins[coin];
        for (int coin = 0; coin < n; coin++)
            cin >> quantity[coin];

        if(k==0) answer = 1;
        else if(k<0) answer = 0;
        else answer = recurse(0, 0);
        
        cout << "Case " << testCase << ": " << answer << endl;
    }

    return 0;
}