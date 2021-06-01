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
    int a,b,s,i,j,n;
    scanf("%d",&n);

    for(j=0;j<n;j++)
    {


        scanf("%d",&a);
        scanf("%d",&b);

        s=0;
        for(i=a;i<=b;i++)
        {
            if(i%2==1)
            {
                s+=i;
            }
        }
        printf("Case %d: %d\n",j+1,s);
    }
    return 0;
}
