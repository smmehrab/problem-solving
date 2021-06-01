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

// 1-based indexing starts from rightside ... (pos)

long long int dp[20][2][100];
char s[20];

long long int recurse(int pos, int smallFlag, int dif){
    if(s[pos] == '\0') return dif==1;

    long long int &ret = dp[pos][smallFlag][dif];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option++){
        if(strlen(s)%2==0){
            if(pos%2==0) ret += recurse(pos+1, option<limit || smallFlag ==1, dif + option);
            else ret += recurse(pos+1, option<limit || smallFlag ==1, dif - option);
        } else{
            if(pos%2==1) ret += recurse(pos+1, option<limit || smallFlag ==1, dif + option);
            else ret += recurse(pos+1, option<limit || smallFlag ==1, dif - option);
        }
    }

    return ret;
}

long long int  solve(long long int  n){
    sprintf(s, "%lld", n);
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0);
}

int main()
{
    long long int  testCaseCount, a, b, answer;
    cin >> testCaseCount;
    while(testCaseCount--){
        cin >> a >> b;
        if(a==0) answer = solve(b);
        else answer = solve(b) - solve(a-1);
        cout << answer << endl;
    }
    return 0;
}