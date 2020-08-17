#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
int n,i,j,k,l[MAX],r[MAX],a[MAX], ans;
char s[MAX];

int main()
{
    scanf("%d %d",&n,&k);
    scanf("%s",s);

    for(i=0;i<n;i++){
        j=s[i]-'A';
        if(!l[j])
            l[j]=i+1;
        r[j]=i+1;
    }


    for(i=0;i<26;i++){
        if(l[i]){
            a[l[i]]++;
            a[r[i]+1]--;
        }
    }

    ans=0;
    for(i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(a[i]>k) ans=1;
    }


    if(ans) puts("YES");
    else puts("NO");

    return 0;
}
