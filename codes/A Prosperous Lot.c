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
    int n,c;
    scanf("%d",&n);

    if(n>36) printf("-1");
    else
    {
        if(n%2==0)
        {
            c=0;
            while(c!=(n/2))
            {
                printf("8");
                c++;
            }
        }
        else
        {
            c=0;
            while(c!=(n-1)/2)
            {
                printf("8");
                c++;
            }
            printf("9");
        }
    }
    printf("\n");
    return 0;
}
