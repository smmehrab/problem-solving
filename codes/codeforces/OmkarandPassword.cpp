#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, ans;
    long long int a[200100];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        if(n==1) ans = 1;
        else{
            int i=0;
            while(i+1<n && a[i]==a[i+1]) i++;

            if(i==n-1) ans=n;
            else ans = 1;
        }

        cout << ans << endl;
    }

    return 0;
}