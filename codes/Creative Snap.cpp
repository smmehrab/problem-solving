/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n,k,a,b;
long long x[100100];

long long dfs(long long l , long long r){
    long long cnt=(r-l+1)/2;
    long long ans;

    int p= upper_bound(x+1, x+1+k, r) - lower_bound(x+1, x+1+k, l);

    if(p==0) return a;
    else ans = (long long) (r-l+1)*b*p;

    if(r-l>=1) ans= min(ans , dfs(l,l+cnt-1) + dfs(l+cnt,r));
    return ans;
}

int main(){
    cin >> n >> k >> a >> b;
    for(int i=1 ; i<=k; i++)
        cin >> x[i];
    sort(x+1,x+1+k);
    cout << dfs(1,1<<n) << endl;
    return 0;
}
