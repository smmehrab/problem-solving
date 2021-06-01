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
    int n,i,j,k=1,max=0,a[100]={0};
    char t[100007];
    scanf("%d",&n);
    scanf("%s", t);
    for(i=0;i<n;i++)
    {
        j=(int)(t[i]-'0');
        a[j]++;
    }

    for(i=0;i<10;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            k=1;
        }
        else if(a[i]==max) k++;
    }

    printf("%d\n",k);

    for(i=0;i<10;i++)
    {
        if(a[i]==max)
        {
            for(j=0;j<max;j++) printf("%c",i+'0');
        }
        printf("\n");
    }

    return 0;
}
