#include <bits/stdc++.h>
using namespace std;

int dp[12][2][12][10005], d, k, divisor;
char s[12];

int recurse(int pos, int smallFlag, int dCount, int remainder){
    if(dCount > k) return 0;
    if(s[pos] == '\0' && dCount==k && remainder==0) return 1;
    if(s[pos] == '\0') return 0;

    int &ret = dp[pos][smallFlag][dCount][remainder];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option++){
        ret += recurse(pos+1, option<limit || smallFlag ==1, dCount + (option==d), (10*remainder + option)%divisor);
    }

    return ret;
}

int solve(int n){
    sprintf(s, "%d", n);
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0, 0);
}

int main()
{
    int a, b, answer;
    cin >> a >> b >> divisor;
    answer = solve(b) - solve(a-1);
    cout << answer << endl;
    return 0;
}