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
    int l,r,a,ll=0,rr=0,i;

    scanf("%d %d %d",&l,&r,&a);

    ll+=l;
    rr+=r;

    while(ll!=rr && a!=0)
    {
        a--;
        if(ll<rr) ll++;
        else rr++;
    }

    if(rr<ll) i=2*rr;
    else i=2*(ll+(a/2));

    printf("%d\n",i);
    return 0;
}
