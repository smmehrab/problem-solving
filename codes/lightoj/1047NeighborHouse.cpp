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

int dp[100][10], n, paintingCost[100][10], answer;

int solve(int house, int neighborColor)
{
    if (house >= 0 && house < n) 
    {   
        int temp = 0;
        if(neighborColor!=-1) temp = neighborColor;     
        int &ret = dp[house][temp];
        if (ret != -1) return ret;
        else ret = INT_MAX;

        for(int color=0; color<3; color++){
            if(color!=neighborColor){
                ret = min(ret, solve(house + 1, color) + paintingCost[house][color]);
            }
        }

        if(house == n-1) ret++;
        return ret;
    }
    else
        return -1;
}

int main()
{   
    int testCaseCount;
    cin >> testCaseCount;
    for(int testCase = 1; testCase <= testCaseCount; testCase++){
        cin >> n;
        for(int house=0; house< n; house++)
            cin >> paintingCost[house][0] >> paintingCost[house][1] >> paintingCost[house][2];
        memset(dp, -1, sizeof(dp));
        answer = solve(0, -1);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}