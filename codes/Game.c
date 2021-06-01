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
    while(1){
    int n1,n2,k1,k2;

    scanf("%d %d %d %d",&n1,&n2,&k1,&k2);

    if(n1>n2)
    {
        printf("First\n");
    }
    else if(n1<n2)
    {
        printf("Second\n");
    }
    else
    {
        if(k1==k2 || k1==1)
        {
            printf("Second\n");
        }
        else if(k1<k2)
        {
            printf("First\n");
        }
        else
        {
            printf("Second\n");
        }
    }

    }
    return 0;
}
