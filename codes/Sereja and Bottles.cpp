/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10000],b[10000],n,i,j,ans=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(b[i]==a[j] && i!=j) a[j]=-1;
        }
    }

    ans=0;
    for(j=0;j<n;j++){
        if(a[j]!=-1) ans++;
    }


    printf("%d\n",ans);
    return 0;
}
