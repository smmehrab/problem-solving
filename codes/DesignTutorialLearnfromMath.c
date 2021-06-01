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

int ifprime(int n)
{int i,flag = 1;for(i=2; i<=n/2; ++i){if(n%i==0){flag=0;break;}}return flag;}

int main()
{

    int n,x,y;
    scanf("%d",&n);

    if((n%2)==0)
    {
        x= y = (n/2);
        while(ifprime(x)==1||ifprime(y)==1)
        {
            x--;
            y++;
        }

    }
    else
    {
            x=(n/2);
            y=x+1;
            while(ifprime(x)==1||ifprime(y)==1)
            {
                    x--;
                    y++;
            }
    }

    printf("%d %d\n",x,y);
    return 0;

}
