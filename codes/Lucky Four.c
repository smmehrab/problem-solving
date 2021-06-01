/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int t,l,ans;
    char n[10000];
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%s", n);
        l=strlen(n);
        while(l--){
            if(n[l]=='4') ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
