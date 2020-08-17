#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a[10000],b[10000]={0},i,c=0,min,max;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    for(i=0;i<n-1;i++) c+=(a[i+1]-a[i]-1);
    printf("%lld\n",c);
    return 0;
}
