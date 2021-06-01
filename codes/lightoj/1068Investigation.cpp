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

int testCaseCount, a, b, k;
long long int dp[12][2][83][83], answer;
char s[12];

long long int recurse(int pos, int smallFlag, int remainder, int sum){
    if(s[pos] == '\0' && remainder==0 && sum==0) return 1;
    if(s[pos] == '\0') return 0;

    long long int &ret = dp[pos][smallFlag][remainder][sum];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option++){
        ret += recurse(pos+1, option<limit || smallFlag ==1, (10*remainder + option)%k, (sum + option)%k);
    }

    return ret;
}

long long int solve(int n){
    sprintf(s, "%d", n);
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0, 0);
}

int main()
{
    cin >> testCaseCount;
    for(int testCase = 1; testCase<=testCaseCount; testCase++){
        cin >> a >> b >> k;
        if(k>=83) answer = 0;
        else if(k==1) answer=b-a+1;
        else answer = solve(b) - solve(a-1);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}