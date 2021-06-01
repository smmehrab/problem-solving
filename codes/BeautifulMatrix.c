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

    int s[5][5];
    int i=1,j=1,x,y,c=0;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&s[i][j]);
            if(s[i][j]==1)
            {
                x=i+1;y=j+1;
            }
            printf("\n");
        }
    }

    if(x>=3) c=c+x-3;
    else c=c+3-x;
    if(y>=3) c=c+y-3;
    else c=c+3-y;

    printf("%d\n",c);
    return 0;
}
