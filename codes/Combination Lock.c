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
int min(int n)
{
    if(n<0){n+=40;}
    return n;
}
int main()
{
    int i,a,b,c,j,k,x,y;

    while(scanf("%d %d %d %d",&i,&a,&b,&c)==4)
    {
        if(i==0 && a==0 && b==0 && c==0) break;
        k=80;
        x=min(a-i);
        y=min(i-a);
        if(x<y)
        {
            k+=x;

        }
        else
        {
            k+=y;
        }
        k+=40;
        k+=min(a-b);
        k+=min(c-b);
        printf("%d\n",(k*9));
    }
    return 0;
}
