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
int abs(int n)
{
    if(n<0) n=(-1)*n;
    return n;
}
int main()
{
    int t,i,j,c,l,a[20000];
    char s[20000],tmp;

    scanf("%d",&t);
    while(t--)
    {
        c=1;
        scanf(" %s%c", s,&tmp);
        j=0;
        l=strlen(s);
        for(i=0;i<l-1;i++)
        {
            a[j]= abs((int) s[i]- (int) s[i+1]);
            j++;
        }
        i=j;
        for(j=0;j<i/2;j++)
        {
            if(a[j]!=a[i-1-j])
            {
                c=0;
                break;
            }
        }
        if(c==1) printf("Funny\n");
        else printf("Not Funny\n");
    }
    return 0;
}
