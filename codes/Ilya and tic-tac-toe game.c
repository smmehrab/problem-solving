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
    int i,j,c,k,m; char s[10][10],temp;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
           if(j!=3)scanf("%c",&s[i][j]);
            else scanf("%c%c",&s[i][j],&temp);
        }
    }

    c=0;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
           if(s[i][j]=='.')
           {
                if(s[i+1][j]=='x'&&s[i-1][j]=='x') c=1;
                else if(s[i][j+1]=='x'&&s[i][j-1]=='x') c=1;
                else if(s[i+1][j+1]=='x'&&s[i-1][j-1]=='x') c=1;
                else if(s[i+1][j-1]=='x'&&s[i-1][j+1]=='x') c=1;
                else if(s[i][j+1]=='x'&&s[i][j+2]=='x') c=1;
                else if(s[i][j-1]=='x'&&s[i][j-2]=='x') c=1;
                else if(s[i+1][j]=='x'&&s[i+2][j]=='x') c=1;
                else if(s[i-1][j]=='x'&&s[i-2][j]=='x') c=1;
                else if(s[i+1][j+1]=='x'&&s[i+2][j+2]=='x') c=1;
                else if(s[i-1][j-1]=='x'&&s[i-2][j-2]=='x') c=1;
                else if(s[i+1][j-1]=='x'&&s[i+2][j-2]=='x') c=1;
                else if(s[i-1][j+1]=='x'&&s[i-2][j+2]=='x') c=1;
           }
        }
    }

    if(c==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
