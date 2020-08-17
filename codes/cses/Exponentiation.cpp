#include <bits/stdc++.h>
using namespace std;

 
int main() {
    long long int testCaseCount, a, b, m;
	cin >> testCaseCount;
    for(int testCase = 1; testCase <= testCaseCount; testCase++){
        cin >> a >> b;
        
    }
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int j = 0; j < m; j++) 
		cin >> b[j];
	
    memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << endl;
	return 0;
}