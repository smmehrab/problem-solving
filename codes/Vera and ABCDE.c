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
    char s[100000];
    int i,j,k,l;

    scanf("%d",&l);
    scanf("%s", s);

    for(j=0;j<5;j++)
    {
        for(i=0;i<l;i++)
        {
            if(s[i]=='A')
            {
                if(j==0) printf("***");
                else if(j==1) printf("*.*");
                else if(j==2) printf("***");
                else if(j==3) printf("*.*");
                else if(j==4) printf("*.*");
            }
            else if(s[i]=='B')
            {
                if(j==0) printf("***");
                else if(j==1) printf("*.*");
                else if(j==2) printf("***");
                else if(j==3) printf("*.*");
                else if(j==4) printf("***");
            }
            else if(s[i]=='C')
            {
                if(j==0) printf("***");
                else if(j==1) printf("*..");
                else if(j==2) printf("*..");
                else if(j==3) printf("*..");
                else if(j==4) printf("***");
            }
            else if(s[i]=='D')
            {
                if(j==0) printf("***");
                else if(j==1) printf("*.*");
                else if(j==2) printf("*.*");
                else if(j==3) printf("*.*");
                else if(j==4) printf("***");
            }
            else if(s[i]=='E')
            {
                if(j==0) printf("***");
                else if(j==1) printf("*..");
                else if(j==2) printf("***");
                else if(j==3) printf("*..");
                else if(j==4) printf("***");
            }
        }
        printf("\n");
    }
    return 0;
}
