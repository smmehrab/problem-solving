#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a, b, c, k;

ll f(ll n) { return a * n + b * n * floor(log2(n)) + c * n * n * n; }

int main() {
    cin >> a >> b >> c >> k;
    ll u = ceil(56 / 3);
    ll l = 1, r = (ll)2 << 56;
    if (c > 0) r = (ll)2 << (ll)(ceil(56 / 3));
    ll ans = 0;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        ll res = f(m);
        if (res == k) {
        ans = m;
        break;
        }

        if (res > k) {
        r = m - 1;
        } else {
        l = m + 1;
        }
    }
    cout << ans << endl;
}