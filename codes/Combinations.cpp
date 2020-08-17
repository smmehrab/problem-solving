#include <bits/stdc++.h>
using namespace std;

int nCrModp(int n, int r, int p) 
{ 
    if(r==0 || r==n){
        return 1;
    }

	if (r > n - r) 
		r = n - r; 

	int dp[r + 1]; 
	memset(dp, 0, sizeof(dp)); 

	dp[0] = 1; 

	for (int i = 1; i <= n; i++) { 
		for (int j = min(i, r); j > 0; j--) {
			dp[j] = ((dp[j]%p) + (dp[j - 1]%p)) % p; 
        }
	} 
	return dp[r]; 
} 

int main()
{
    int testCaseCount, n, k, answer;
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d", &n, &k);
        answer = nCrModp(n, k, 1000003);
        printf("Case %d: %d\n", testCase, answer);
    }
    return 0;
}