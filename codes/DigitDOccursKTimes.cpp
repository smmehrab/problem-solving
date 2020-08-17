#include <bits/stdc++.h>
using namespace std;

int dp[12][2][12], d, k;
char s[12];

int recurse(int pos, int smallFlag, int dCount){
    if(dCount > k) return 0;
    if(s[pos] == '\0' && dCount==k) return 1;
    if(s[pos] == '\0') return 0;

    int &ret = dp[pos][smallFlag][dCount];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option+=1){
        ret += recurse(pos+1, option<limit || smallFlag ==1, dCount + (option==d));
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
    cout << answer << endl;
    return 0;
}