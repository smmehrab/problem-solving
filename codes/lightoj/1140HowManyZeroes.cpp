#include <bits/stdc++.h>
using namespace std;

long long int dp[20][2][2][20], answer;
char s[20];

long long int recurse(int pos, int smallFlag, int zeroFlag, int zeros){
    if(s[pos] == '\0') return zeros;

    long long int &ret = dp[pos][smallFlag][zeroFlag][zeros];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option++){
        if(option!=0) 
            ret += recurse(pos+1, option<limit || smallFlag ==1, 1, zeros);
        else if(zeroFlag==1) 
            ret += recurse(pos+1, option<limit || smallFlag ==1, zeroFlag, zeros+1);
        else
            ret += recurse(pos+1, option<limit || smallFlag ==1, zeroFlag, zeros);
    }

    return ret;
}

long long int solve(long long int n){
    sprintf(s, "%lld", n);
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0, 0);
}

int main()
{
    int testCaseCount;
    long long int a, b;
    cin >> testCaseCount;
    for(int testCase = 1; testCase<=testCaseCount; testCase++){
        cin >> a >> b;
        if(a==0) answer = solve(b)+1;
        else answer = solve(b) - solve(a-1);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}