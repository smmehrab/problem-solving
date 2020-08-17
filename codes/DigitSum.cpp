#include <bits/stdc++.h>
using namespace std;

long long int dp[20][2][200];
char s[20];

long long int recurse(int pos, int smallFlag, int sum){
    if(s[pos] == '\0') return sum;

    long long int &ret = dp[pos][smallFlag][sum];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option++){
        ret += recurse(pos+1, option<limit || smallFlag ==1, sum + option);
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