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
#include<string.h>
int main()
{
    int n,m,i,j,k,l[1000],al,c,r;
    char a[10000],temp;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s%c", a,&temp);
        l[i]=strlen(a);
    }
    scanf("%s%c", a,&temp);
    al=strlen(a);

    c=0;
    for(i=0;i<n;i++)
    {
        if(l[i]<al) c++;
    }
    r=(((c/m)*5)+c)+1;

    printf("%d ",r);
    c=0;
    for(i=0;i<n;i++)
    {
        if(l[i]>al) c++;
    }

    c=(n-1-c);

    r=(((c/m)*5)+c)+1;

    printf("%d\n",r);
    return 0;
}
