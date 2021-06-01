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
    int a,b,c,t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        printf("Case %d: ",++cs);
        if((((a*a)+(b*b))==(c*c))||(((a*a)+(c*c))==(b*b))||(((c*c)+(b*b))==(a*a))){
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}
