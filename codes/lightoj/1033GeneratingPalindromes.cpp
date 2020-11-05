#include <bits/stdc++.h>
using namespace std;

string s;
int dp[103][103];

int solve(int start, int end) {
	if (start>=end) return 0;
	if (dp[start][end]!=-1) return dp[start][end];
	
    dp[start][end] = (s[start]==s[end]) ? solve(start+1, end-1) : 1 + min(solve(start+1, end), solve(start, end-1));
    return dp[start][end];
}

int main() {
	int testCaseCount, answer;

	cin >> testCaseCount;
	for (int testCase=1; testCase<=testCaseCount; testCase++) {
		cin >> s;
		memset(dp, -1, sizeof(dp));
		answer = solve(0, s.size()-1);
        cout << "Case " << testCase << ": " << answer << endl;
	}

	return 0;
}