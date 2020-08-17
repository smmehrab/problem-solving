#include <bits/stdc++.h>
using namespace std;

int dp[20][(1 << 16) + 10], n, priorityIndex[20][20], answer;

int setMask(int mask, int pos)
{
    return mask = mask | (1 << pos);
}

bool checkMask(int mask, int pos)
{
    return (bool)(mask & (1 << pos));
}

int solve(int man, int taken)
{
    if (man == n)
        return 0;

    int &ret = dp[man][taken];
    if (ret != -1)
        return ret;

    for (int woman = 0; woman < n; woman++)
    {
        if (!checkMask(taken, woman))
            ret = max(ret, solve(man + 1, setMask(taken, woman)) + priorityIndex[man][woman]);
    }

    return ret;
}

int main()
{
    int testCaseCount;
    cin >> testCaseCount;
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n;
        for (int man = 0; man < n; man++)
        {
            for (int woman = 0; woman < n; woman++)
            {
                cin >> priorityIndex[man][woman];
            }
        }
        memset(dp, -1, sizeof(dp));
        answer = solve(0, 0);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}