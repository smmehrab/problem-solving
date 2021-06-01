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
    int t,i,j,k,l,a,first;
    char s[100000],c;
    scanf("%d%c",&t,&c);
    while(t--)
    {
        scanf("%[^\n]%*c", s);
        first=1;
        l=strlen(s);
        i=0;
        s[0]+=32;
        c=s[0];
        k=0;
        while(i<l)
        {
            if(s[i]==' ')
            {
                printf("%cay ",c);
                c=s[i+1];
                k=0;
            }
            else if(k++)
            {
                if(first==1 && s[i]>'Z')
                {
                    s[i]-=32;
                    first=0;
                }
                printf("%c",s[i]);
            }
            i++;
        }
        if(first==1) c-=32;
        printf("%cay\n",c);
    }
    return 0;
}
