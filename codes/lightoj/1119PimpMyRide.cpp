/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

int dp[(1 << 15) + 2], cost[20][20], n, minimumCost;

int setMask(int mask,int pos){return mask=mask | (1<<pos);}
int resetMask(int mask,int pos){return mask= mask & ~(1<<pos);}
bool checkMask(int mask,int pos){return (bool)(mask & (1<<pos));}

int solve(int mask)
{
    if (mask == (1 << n) - 1)
        return 0;
    
    int &ret = dp[mask];
    if (ret != -1)
        return ret;

    ret = 1 << 28;
    for (int i = 0; i < n; i++) {
        if (checkMask(mask, i) == 0) {
            int currentCost = cost[i][i];
            for (int j = 0; j < n; j++) {
                if (i != j && checkMask(mask, j) != 0) {
                    currentCost += cost[i][j];
                }
            }
            ret = min(ret, currentCost + solve(setMask(mask, i)));
        }
    }
    return ret;
}

int main()
{
    int testCaseCount;
    cin >> testCaseCount;
    for(int testCase = 1; testCase <= testCaseCount; testCase++){
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> cost[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        minimumCost = solve(0);
        cout << "Case " << testCase << ": " << minimumCost << endl;
    }
    return 0;
}