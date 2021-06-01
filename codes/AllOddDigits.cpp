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

int dp[12][2][2];
char s[12];

int recurse(int pos, int smallFlag, int zeroFlag){
    if(s[pos]=='\0') return 1;
    
    int &ret = dp[pos][smallFlag][zeroFlag];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;

    if(zeroFlag==0) ret += recurse(pos+1, 1, 0);

    for(int option = 1; option <= limit; option+=2){
        ret += recurse(pos+1, option<limit || smallFlag ==1, 1);
    }

    return ret;
}

int solve(int n){
    sprintf(s, "%d", n);
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0);
}

int main()
{
    int a, b, answer;
    cin >> a >> b;
    answer = solve(b) - solve(a-1);
    cout << solve(b) << " " << solve(a-1) << endl;
    cout << answer << endl;
    return 0;
}