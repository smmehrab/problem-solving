#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    long long int a[500100], x, y, z;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        x = 1;
        y = 2;

        z = -1;
        for(int i=2; i<n; i++){
            if(a[i]>=a[x-1]+a[y-1]){
                z = i+1;
                break;
            }
        }

        if(z==-1) cout << z << endl;
        else cout << x << " " << y << " " << z << endl;
    }

    return 0;
}