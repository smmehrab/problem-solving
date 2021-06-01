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
    int m,n,p,c,i,j,k,l,a[100000];
    scanf("%d",&n);
    m=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i!=0)
        {
            c=a[i]-a[i-1];
            if(c<0) c*=-1;
            if(c>m) m=c;
        }
    }
    printf("%d\n",m);
    return 0;

}
