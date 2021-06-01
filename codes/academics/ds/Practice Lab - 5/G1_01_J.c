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
    int r,c,i,j,m[100][100];
    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    printf("Row-wise: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",m[i][j]);
            if(j!=c-1) printf(" ");
        }
        if(i!=r-1) printf(" ");
    }
    printf("\n");
    printf("Column-wise: ");
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d",m[j][i]);
            if(j!=r-1) printf(" ");
        }
        if(i!=c-1) printf(" ");
    }
    printf("\n");
    return 0;
}
