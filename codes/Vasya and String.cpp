#include<bits/stdc++.h>
using namespace std;

bool possibileSubstring( string s , int k , int l ){
	int i,j,dp[2] = {0 , 0};

	for(i = 0; i < l; i++ )
        dp[s[i] - 'a']++;
	if(k >= min(dp[0],dp[1]))
        return 1;

	for(i = 0; i + l <(int)s.size(); i++ ){
		dp[s[i] - 'a']--;
		dp[s[i + l] - 'a']++;
		if(k >= min(dp[0],dp[1]))
            return 1;
	}

	return 0;
}

int main(){
	int n , i, j, k, l, r, ans = 0, mid;
	string s;

	cin >> n >> k;
	cin >> s;

	for(l = 1, r = n;l<=r;){
		mid = (l + r ) >> 1;

		if(possibileSubstring(s , k , mid )){
			ans = max( ans , mid );
			l = mid + 1;
		}

		else r = mid - 1;
	}

	cout << ans;
	return 0;
}
