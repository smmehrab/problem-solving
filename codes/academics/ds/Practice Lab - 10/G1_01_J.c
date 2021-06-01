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
    char s[10][10];
    memset(s, '.', 100*sizeof(char));
    int i,j,k=0,v=1;

    for(i=0;i<5;i++) scanf("%s", s[i]);

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(s[i][j]=='k')
            {
                k++;
               if(s[i+1][j+2]=='k') {v=0;break;}
               else if(s[i-1][j+2]=='k') {v=0;break;}
               else if(s[i+1][j-2]=='k') {v=0;break;}
               else if(s[i-1][j-2]=='k') {v=0;break;}
               else if(s[i+2][j+1]=='k') {v=0;break;}
               else if(s[i+2][j-1]=='k') {v=0;break;}
               else if(s[i-2][j+1]=='k') {v=0;break;}
               else if(s[i-2][j-1]=='k') {v=0;break;}
            }
        }
    }

    if(v==0 || k!=9) printf("invalid\n");
    else printf("valid\n");
    return 0;
}
