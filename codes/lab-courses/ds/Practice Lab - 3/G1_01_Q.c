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
int digsum(int d)
{
    int k;
    if(d<10) return d;
    k=0;
    k+=(d/100000);
    d=d%100000;
    if(d==0) return k;
    k+=(d/10000);
    d=d%10000;
    if(d==0) return k;
    k+=(d/1000);
    d=d%1000;
    if(d==0) return k;
    k+=(d/100);
    d=d%100;
    if(d==0) return k;
    k+=(d/10)+(d%10);
    return k;
}
int main()
{
    int t,i,n,j,g,d;

    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        g=0;d=0;
        scanf("%d",&n);
        for(j=n-1;j>n-60;j--)
        {
            d=digsum(j);

            d+=j;
            if(d==n) g=j;
        }
        printf("%d\n",g);
    }
    return 0;

}
