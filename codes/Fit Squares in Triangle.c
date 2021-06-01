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
    int t,b,ans;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&b);
        b=(b-2)/2;
        ans=b*(b+1)/2;
        printf("%d\n",ans);
    }
    return 0;
}
