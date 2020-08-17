#include <bits/stdc++.h>
using namespace std;

long long int m = 10000011;
int main()
{
    long long int n,t,s,d,i,j,k, ans;

    cin >> n >> t;
    for(i=1;i<=n;i++){
        cin >> s >> d;
        j=s-t;
        if(j==0){
            ans = i;
            m = j;
        }
        else if(j>0){
            if(j<m)
                ans = i;
            m = min(m,j);
        }
        else{
            k=(t-s)%d;
            if(k) j=d-k;
            else j=0;

            if(j<m)
                ans = i;
            m = min(m,j);
        }
    }

    cout << ans << endl;
    return 0;
}

