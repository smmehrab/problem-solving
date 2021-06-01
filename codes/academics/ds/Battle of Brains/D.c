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
    int t,cs=0,l,i;
    char n[100000],temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%c", n,&temp);
        l=strlen(n);
        printf("Case %d: %s",++cs, n);
        if(l-2>=0)
        {
            for(i=l-2;i>=0;i--) {printf("%c",n[i]);}
        }
        printf("\n");
    }
    return 0;
}
