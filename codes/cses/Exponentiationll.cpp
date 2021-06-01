/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll solve(ll a, ll b, ll c, ll m){
	if(b==0) return 1;
	else{
		ll r = solve(a, (b/2), (c/2), m);
		r = (r*r)%m;
		return (b%2==0) ? r : (r*a)%m;
	}
}

int main() {
    ll t, a, b, c, m=1e9+7;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		cout << solve(a, b, c, m) << endl;
	}
	return 0;
}