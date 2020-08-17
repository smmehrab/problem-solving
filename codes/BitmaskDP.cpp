#include <bits/stdc++.h>
using namespace std;

// Find the number of numbers 
// within a range,
// that contains all the digits 0-9,
// at least once

int dp[20][2][1024];
char s[20];

int recurse(int pos, int smallFlag, int bitmask){
    if(s[pos] == '\0') return bitmask == 1023;

    int &ret = dp[pos][smallFlag][bitmask];
    if(ret!=-1) return ret;

    int limit=9;
    if(smallFlag==0) limit = s[pos] - '0';

    ret=0;
    for(int option = 0; option <= limit; option++){
        ret += recurse(pos+1, option<limit || smallFlag ==1, bitmask | (1 >> option));
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