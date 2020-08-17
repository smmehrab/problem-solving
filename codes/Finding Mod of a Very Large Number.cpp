#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x, ll y, ll p){
	ll res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

int main(){
	ll a = 3;
	string b = "100000000000000000000000000";

	ll remainderB = 0;
	ll MOD = 1000000007;

	for (int i = 0; i < b.length(); i++)
		remainderB = (remainderB * 10 + b[i] - '0') % (MOD - 1);
	cout << power(a, remainderB, MOD) << endl;
	return 0;
}

