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

    int n;char t[4];
    scanf("%d %s",&n, t);

    int i;

    if(t[0]=='1'&& t[1]=='0')
    {
        if(n==1)
        {
            printf("-1\n");
            return 0;
        }
        for(i=0;i<n-1;i++)
        {
            printf("%c",t[0]);

        }
        printf("0\n");
    }
    else{
    for(i=0;i<n;i++)
    {
        printf("%c",t[0]);
    }
    printf("\n");
    }

}
