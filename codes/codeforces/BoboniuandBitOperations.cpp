#include <bits/stdc++.h>
using namespace std;

int n, m, a[300], b[300], dp[300][600];
 
int solve(int index, int result) {
	if (index >= n) return result;
	
    int &ret = dp[index][result];
	if (ret != -1) return ret;
	else ret = INT_MAX;
	
    for (int j = 0; j < m; j++) {
		int c = (a[index] & b[j]);
		ret = min(ret, solve(index+1, (result | c)));
	}

	return ret;
}
 
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int j = 0; j < m; j++) 
		cin >> b[j];
	
    memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << endl;
	return 0;
}