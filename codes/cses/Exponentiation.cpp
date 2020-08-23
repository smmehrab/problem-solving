#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll solve(ll a, ll b, ll m){
	if(b==0) return 1;
	else{
		ll r = solve(a, (ll)(b/2), m);
		r = (r*r)%m;
		return (b%2==0) ? r : (r*a)%m;
	}
}

int main() {
    ll t, a, b, m=1e9+7;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << solve(a, b, m) << endl;
	}
	return 0;
}