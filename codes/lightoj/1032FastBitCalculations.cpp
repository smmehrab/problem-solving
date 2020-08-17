#include <bits/stdc++.h>
#include <limits.h>
#include <string>
using namespace std;

long long int  dp[32][2][32][2];
string s;

long long int  recurse(int pos, int smallFlag, int adjacentBits, int current){
    if(pos==31) return adjacentBits;

    long long int  &ret = dp[pos][smallFlag][adjacentBits][current];
    if(ret!=-1) return ret;

    int limit=1;
    if(smallFlag==0) limit = s[pos] - '0';

    ret = 0;

    if(smallFlag==1 || limit==1){
        ret += recurse(pos+1, 1, adjacentBits, 0);
        if(current == 1) ret += recurse(pos+1, smallFlag, adjacentBits+1, 1);
        else ret += recurse(pos+1, smallFlag, adjacentBits, 1);
    }
    else ret += recurse(pos+1, smallFlag, adjacentBits, 0);
    
    return ret;
}

long long int solve(long long int n){
    s = bitset<31>(n).to_string();
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0, 0);
}


int main() {
    long long int testCaseCount, testCase, n, answer;
    cin >> testCaseCount;
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        cin >> n;
        answer = solve(n);
        cout << "Case " << testCase << ": " << answer << endl;
    }
    return 0;
}