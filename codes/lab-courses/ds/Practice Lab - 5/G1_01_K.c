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
    int d=0,i,j,m[100][100];

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    d+=(m[0][0]*((m[1][1]*m[2][2]) - (m[1][2]*m[2][1])));
    d-=(m[0][1]*((m[1][0]*m[2][2]) - (m[1][2]*m[2][0])));
    d+=(m[0][2]*((m[1][0]*m[2][1]) - (m[1][1]*m[2][0])));

    printf("%d\n",d);

    return 0;
}

