#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long int testCases, n, k, a, g;
    string ans;
    cin >> testCases;

    while (testCases--) {
        g = 0;
        ans = "YES";
        
        cin >> n >> k;
        while(n--){
            cin >> a;
            g = gcd(g, a); 
        }

        for (int factor=2; factor*factor <= g; factor++) {
            if (g%factor == 0) {
                if (factor>k) {
                    ans = "NO";
                    break;
                }
                while (g%factor == 0) g /= factor;
            }
        }

        ans = (g>k) ? "NO" : ans;
        cout << ans << endl;
    }

    return 0;
}