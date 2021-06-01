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
    int n,m,t,cs=0,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(m>=n) r=(m*4)+19;
        else r=((n-m)+n)*4+19;
        printf("Case %d: %d\n",++cs,r);
    }
    return 0;
}
