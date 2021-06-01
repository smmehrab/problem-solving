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
    int n,t,x,y,one=1,two=1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&t,&x,&y);
        if(t==1) one+=(x-y);
        else two+=(x-y);
    }
    if(one==0 || two==0) printf("NO\n");
    else printf("YES\n(%d, %d)\n",one,two);
    return 0;
}
