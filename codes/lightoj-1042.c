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

int main()
{
    int N,T,c0;
    scanf("%d",&N);
    c0=count_one(N);
    printf("%d",c0);



}

int count_one(int N)
{

    int n=0;
    int i,c=0;
    for(n=0;n=(N/2);n++)
    {
        int y=(pow(2,n));
        if(y<=N)
        {
            continue;

        }n=n-1; break;
    }

    for(i=n;i<=n;i--)
    {   int x=(pow(2,i));
        if((N/x)!=0)
        {
            c++;

            N=N%x;

        }

    }
    return c;


}
