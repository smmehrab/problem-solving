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
int max_of_four(int a, int b, int c, int d)
{
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(d>max) max=d;
    return max;
}

int main()
{
    int a,b,c,d,m;
    scanf("%d",&a);
        scanf("%d",&b);
            scanf("%d",&c);
                scanf("%d",&d);
    m=max_of_four(a,b,c,d);
    printf("%d\n",m);
    return 0;
}
