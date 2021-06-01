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
    int n,th,rank,others,i,j,a,b,c,d;

    scanf("%d",&n);
    scanf("%d %d %d %d",&a,&b,&c,&d);
    th=a+b+c+d;
    rank=1;
    for(i=1;i<n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        others=a+b+c+d;
        if(others>th) rank++;
    }
    printf("%d\n",rank);
    return 0;
}
