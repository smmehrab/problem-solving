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

    int n,a,b,c,i=0,x=0,y=0,z=0;
    scanf("%d",&n);
    while(i<(3*n))
    {
        scanf("%d %d %d",&a,&b,&c);
        x=x+a;
        y=y+b;
        z=z+c;
        i=i+3;
    }

    if(x==0 && y==0 && z==0)
    {
        printf("YES\n");

    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
