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
    int i,j,k,m1[100][100],m2[100][100],t[100][100]={0};

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&m1[i][j]);
            }
        }

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&m2[i][j]);
            }
        }

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    t[i][j]+=(m1[i][k]*m2[k][j]);
                }
            }
        }

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d",t[i][j]);
                if(j!=2) printf(" ");
            }
            printf("\n");
        }

    return 0;
}

