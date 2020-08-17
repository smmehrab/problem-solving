#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll testCaseCount, n, ans;
    string s;
    cin >> testCaseCount;
    while(testCaseCount--){
        cin >> n;
        cin >> s;
        ans = 0;

        map<ll,ll> counter;
        counter[0] = 1;
        for(int i=0, sum=(s[i]-'0'); i<n; i++, sum+=(s[i]-'0'))
            counter[sum - (i + 1)]++;
        
        for(map<ll, ll>::iterator it = counter.begin(); it!=counter.end(); it++)
            ans += (it->second)*(it->second-1)/2;
        
        cout << ans << endl;
    }
    return 0;
}