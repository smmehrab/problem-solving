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
int main()
{
    int t,r,c,ans=0,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&r,&c);
        if(r+1<=8 && c+2<=8 ) ans++;
        if(r-1>0 && c+2<=8 ) ans++;
        if(r+1<=8 && c-2>0 ) ans++;
        if(r-1>0 && c-2>0 ) ans++;
        if(c+1<=8 && r+2<=8 ) ans++;
        if(c-1>0 && r+2<=8 ) ans++;
        if(c+1<=8 && r-2>0 ) ans++;
        if(c-1>0 && r-2>0 ) ans++;
        printf("Case %d: %d\n",++cs, ans);
    }

    return 0;
}
