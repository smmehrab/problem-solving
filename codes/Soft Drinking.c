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

int min(int a, int b, int c)
{
        if(a<=b && a<=c) return a;
        if(b<=a && b<=c) return b;
        if(c<=b && c<=a) return c;
}

int main()
{
    int n,k,l,c,d,p,nl,np,i,j,slice,mlitres,r;

    scanf("%d %d %d %d %d %d %d %d",&n,&k,&l,&c,&d,&p,&nl,&np);

    slice=(c*d);
    mlitres=(k*l)/nl;
    p=(p/np);

    r=min(slice,mlitres,p);

    printf("%d\n",r/n);
    return 0;

}
