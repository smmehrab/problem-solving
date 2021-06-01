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

    int x;
    scanf("%d",&x);

    int s5=0,s4=0,s3=0,s2=0,s1=0,r5,r4,r3,r2,r1;

    s5=(x/5);
    r5=(x%5);
    if(r5!=0)
    {
        s4=(r5/4);
        r4=(r5%4);

    if(r4!=0)
    {
            s3=(r4/3);
            r3=(r4%3);

    if(r3!=0)
    {
        s2=(r3/2);
        r2=(r3%2);

    if(r2!=0)
    {
        s1=r2;
    }
    }}}

    int s=s1+s2+s3+s4+s5;

    printf("%d\n",s);
    return 0;

}
