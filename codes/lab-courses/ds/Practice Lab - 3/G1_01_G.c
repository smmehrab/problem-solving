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
unsigned long long int algo(unsigned long long int n)
{
    unsigned long long int b=0;
    while(1)
    {
        if(n==1){b++;return b;}

        b++;
        if((n%2)==1) {n=(3*n)+1;}
        else {n=n/2;}
    }
}
int main()
{
    unsigned long long int i,j,a,max,l;

    while(scanf("%llu %llu",&i,&j)==2)
    {
        max=0;
            if(i<j)
            {
                a=i;
                while(a<=j)
                {
                    l=algo(a);

                    if(l>max) {max=l;}
                    a++;
                }
            }
            else
            {
                a=j;
                while(a<=i)
                {
                    l=algo(a);

                    if(l>max) {max=l;}
                    a++;
                }
            }
        printf("%llu %llu %llu\n",i,j,max);
    }
    return 0;
}
