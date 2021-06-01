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
#include<math.h>

int ifps(int n)
{
    if(n<0) return 0;

    int i=sqrt(n);
    if((i*i)==n) return 1;
    else return 0;
}

int main()
{
    int n,t,r,c=0;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        if(ifps(t)==0)
        {
            if(c==0)
            {r=t;c=1;}

            else if(t>r) r=t;
        }
    }
    printf("%d\n",r);
    return 0;
}
