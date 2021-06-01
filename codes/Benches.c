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
    int n,m,a[100000],i,j,k,l,max,min,s=0,mina;
    scanf("%d",&n);
    scanf("%d",&m);
    min=(m/n);
    if(m%n!=0) min++;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
        if(i==0) max=mina=a[i];
        if(a[i]>max) max=a[i];
        if(a[i]<mina) mina=a[i];
    }
    min=(m+s)/n;
    if((m+s)%n!=0) min++;
    if(max>min) min=max;
    max+=m;
    printf("%d %d\n",min,max);
    return 0;
}
