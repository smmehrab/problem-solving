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
    int t,cs=0,n,p,q,ew,w,c,i,j=1;
    scanf("%d",&t);
    while(t--)
    {
        c=0; w=0; j=1;
        scanf("%d %d %d",&n,&p,&q);
        for(i=0;i<n;i++){
            scanf("%d",&ew);
            if(j && (w+ew)<=q) w+=ew;
            else j=0;
            if(j && c+1<=p) c++;
            else j=0;
        }
        printf("Case %d: %d\n",++cs,c);
    }
    return 0;
}
